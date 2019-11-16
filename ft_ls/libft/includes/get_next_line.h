/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:32:56 by clothor-          #+#    #+#             */
/*   Updated: 2019/02/28 15:34:42 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 32

typedef	struct		s_gnl {
	int				fd;
	char			*buff;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
#endif
