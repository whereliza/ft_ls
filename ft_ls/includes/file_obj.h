/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_obj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:02:52 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:56:41 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OBJ_H
# define FILE_OBJ_H

# include "libft.h"

typedef struct		s_f_stat
{
	char			*name;
	char			*path;
	char			file_type;
	char			*link;
	char			*permissions;
	long			link_count;
	char			*user;
	char			*group;
	unsigned int	minor;
	unsigned int	major;
	long long		file_size;
	long long		blocks_allocated;
	time_t			last_modification;
}					t_f_stat;

typedef struct		s_dnode
{
	t_f_stat		*dir_stats;
	t_list			*f_list;
}					t_dnode;

typedef struct		s_wlists
{
	t_list			*dir_list;
	t_list			*file_list;
	t_list			*nonexistent_list;
}					t_wlists;

void				free_dnode_list(t_list **list);
void				free_file_obj(t_f_stat **file_stat);
void				free_wlists(t_wlists *wlists);

#endif
