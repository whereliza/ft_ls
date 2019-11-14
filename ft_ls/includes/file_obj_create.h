/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_obj_create.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 08:35:22 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 21:53:58 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OBJ_CREATE_H
# define FILE_OBJ_CREATE_H

# include "file_obj.h"
# include "permissions.h"
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>

int			fill_file_stat(t_f_stat **file_stat, struct stat file_info);
void		init_wlists(t_wlists *wlists);
t_f_stat	*new_file_stat(char *path, char *name);

#endif
