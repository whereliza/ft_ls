/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_obj_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 08:35:08 by clothor-          #+#    #+#             */
/*   Updated: 2019/11/11 21:52:15 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			fill_file_stat_sq(t_f_stat **file_stat, struct stat file_info)
{
	ssize_t r;

	(*file_stat)->link_count = file_info.st_nlink;
	(*file_stat)->file_size = file_info.st_size;
	(*file_stat)->blocks_allocated = file_info.st_blocks;
	(*file_stat)->minor = minor(file_info.st_rdev);
	(*file_stat)->major = major(file_info.st_rdev);
	if ((*file_stat)->file_type == 'l')
	{
		(*file_stat)->link = ft_strnew(file_info.st_size + 1);
		r = readlink((*file_stat)->path,
				(*file_stat)->link, file_info.st_size + 1);
		if (r < 0 || r > file_info.st_size)
		{
			ft_strdel(&((*file_stat)->link));
			(*file_stat)->link = ft_strnew(23);
			ft_strcpy((*file_stat)->link, "error: target not found");
		}
		else
			(*file_stat)->link[file_info.st_size] = '\0';
	}
	else
		(*file_stat)->link = NULL;
	(*file_stat)->last_modification = file_info.st_mtime;
	return (1);
}

int			fill_file_stat(t_f_stat **file_stat, struct stat file_info)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!((*file_stat)->permissions = get_file_permissions(file_info.st_mode,
					(*file_stat)->path)))
		return (-1);
	(*file_stat)->file_type = (*file_stat)->permissions[0];
	if ((pwd = getpwuid(file_info.st_uid)) != NULL)
	{
		if (!((*file_stat)->user = ft_strdup(pwd->pw_name)))
			return (-1);
	}
	else if (!((*file_stat)->user = ft_strdup(ft_itoa(file_info.st_uid))))
		return (-1);
	if ((grp = getgrgid(file_info.st_gid)) != NULL)
	{
		if (!((*file_stat)->group = ft_strdup(grp->gr_name)))
			return (-1);
	}
	else if (!((*file_stat)->group = ft_strdup(ft_itoa(file_info.st_gid))))
		return (-1);
	return (fill_file_stat_sq(file_stat, file_info));
}

void		init_wlists(t_wlists *wlists)
{
	wlists->dir_list = NULL;
	wlists->file_list = NULL;
	wlists->nonexistent_list = NULL;
}

t_f_stat	*new_file_stat(char *path, char *name)
{
	t_f_stat *file_stat;

	if (!(file_stat = (t_f_stat*)malloc(sizeof(t_f_stat))))
		return (NULL);
	if (!(file_stat->name = ft_strdup(name)))
	{
		free(file_stat);
		return (NULL);
	}
	if (!(file_stat->path = ft_strdup(path)))
	{
		if (file_stat->name)
			ft_strdel(&(file_stat->name));
		free(file_stat);
		return (NULL);
	}
	file_stat->link = NULL;
	file_stat->permissions = NULL;
	file_stat->user = NULL;
	file_stat->group = NULL;
	return (file_stat);
}
