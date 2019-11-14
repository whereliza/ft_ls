/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:13:05 by gpop              #+#    #+#             */
/*   Updated: 2018/02/15 19:00:36 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_UTILS_H
# define CONSOLE_UTILS_H

# include "libft.h"
# include "file_obj.h"
# include "error.h"
# include <stdio.h>

typedef struct	s_c_widths
{
	int			lc_width;
	int			uid_width;
	int			group_width;
	int			fs_width;
	int			longest_major;
}				t_c_widths;

void			fill_c_widths(t_list *f_list, t_c_widths *cwidths);
void			print_nonexistent(t_list *list);
void			ft_perror(char *str);
#endif
