/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wizard.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:58:13 by clothor-          #+#    #+#             */
/*   Updated: 2019/10/15 16:53:50 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wizard.h"

t_list	*get_file_stat(char *path, char *flags, int isarg)
{
	struct stat	file_info;
	t_f_stat	*file_stat;
	t_list		*file_stat_node;

	if (!isarg && ((is_hidden(path) && (!flags || (flags[1] != 'a' &&
		flags[8] != 'A'))) || (flags && flags[8] == 'A' && flags[1] != 'a' &&
		(ft_strequ("..", get_filename(path)) || ft_strequ(".",
		get_filename(path))))))
		return (NULL);
	if ((isarg && !(file_stat = new_file_stat(path, path))) ||
			(!isarg && !(file_stat = new_file_stat(path, get_filename(path)))))
		return (NULL);
	if (lstat(path, &file_info) != 0)
		file_stat->file_type = 'X';
	else if (fill_file_stat(&file_stat, file_info) == -1)
	{
		free_file_obj(&file_stat);
		return (NULL);
	}
	file_stat_node = ft_lstnew(NULL, 0);
	file_stat_node->content = file_stat;
	file_stat_node->content_size = sizeof(file_stat);
	return (file_stat_node);
}

char	*append_path(char *firstpath, char *secondpath)
{
	char	*str;
	char	*temp;

	if (!(temp = ft_strjoin(firstpath, "/")))
		return (NULL);
	if (!(str = ft_strjoin(temp, secondpath)))
		return (NULL);
	ft_strdel(&temp);
	return (str);
}

t_list	*get_dir_stat(char *path, char *flags)
{
	DIR				*dir_p;
	struct dirent	*dir_element;
	t_list			*list;
	t_list			*node;
	char			*filepath;

	list = NULL;
	if ((dir_p = opendir(path)))
		while ((dir_element = readdir(dir_p)))
		{
			if (!(filepath = append_path(path, dir_element->d_name)))
				return (NULL);
			if ((node = get_file_stat(filepath, flags, 0)))
				ft_lstappend(&list, node);
			ft_strdel(&filepath);
		}
	return (list);
}
