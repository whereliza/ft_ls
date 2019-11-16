/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:28:46 by clothor-          #+#    #+#             */
/*   Updated: 2019/02/28 15:28:47 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*get_fd(int fd, t_gnl **list)
{
	t_gnl			*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	ft_memset(tmp, '\0', sizeof(t_gnl));
	if (!(tmp->buff = ft_strnew(0)))
		return (NULL);
	tmp->fd = fd;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static char			*get_line(char **join, char **line)
{
	unsigned int	i;
	char			*new;
	char			*buff;

	i = 0;
	buff = *join;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!(*line = ft_strsub(*join, 0, i)))
		return (NULL);
	if (buff[i] == '\n')
		i++;
	if (!(new = ft_strsub(*join, i, ft_strlen(&buff[i]))))
		return (NULL);
	free(*join);
	*join = NULL;
	return (new);
}

static char			*get_buff(char **join, char *str)
{
	char			*new;

	new = *join;
	if (new)
	{
		if (!(new = ft_strjoin(new, str)))
			return (NULL);
		free(*join);
		*join = NULL;
	}
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_gnl	*fd_list;
	ssize_t			ret;
	t_gnl			*wfd;

	if (!line || fd < 0 || BUFF_SIZE < 0 || read(fd, buff, 0) < 0)
		return (-1);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	if (!(wfd = get_fd(fd, &fd_list)))
		return (-1);
	while (!ft_strchr(buff, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(wfd->buff = get_buff(&wfd->buff, buff)))
			return (-1);
	}
	if (ft_strlen(wfd->buff) > 0)
	{
		if (!(wfd->buff = get_line(&wfd->buff, line)))
			return (-1);
		return (1);
	}
	return (0);
}
