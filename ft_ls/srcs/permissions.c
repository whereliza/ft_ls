/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:21:58 by clothor-          #+#    #+#             */
/*   Updated: 2019/10/14 19:31:26 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_file_type(mode_t st_mode)
{
	if ((st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	else if ((st_mode & S_IFMT) == S_IFREG)
		return ('-');
	else
		return ('?');
}

char	get_xattr_or_acl(char *filename)
{
	acl_t		acl;
	acl_entry_t	dummy;

	if (listxattr(filename, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	acl = acl_get_link_np(filename, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	if (acl)
		return ('+');
	return (' ');
}

char	*get_file_permissions(mode_t st_mode, char *filename)
{
	char *permissions;

	if (!(permissions = ft_strnew(11)))
		return (NULL);
	permissions[0] = get_file_type(st_mode);
	permissions[1] = st_mode & S_IRUSR ? 'r' : '-';
	permissions[2] = st_mode & S_IWUSR ? 'w' : '-';
	permissions[3] = st_mode & S_IXUSR ? 'x' : '-';
	permissions[4] = st_mode & S_IRGRP ? 'r' : '-';
	permissions[5] = st_mode & S_IWGRP ? 'w' : '-';
	permissions[6] = st_mode & S_IXGRP ? 'x' : '-';
	permissions[7] = st_mode & S_IROTH ? 'r' : '-';
	permissions[8] = st_mode & S_IWOTH ? 'w' : '-';
	permissions[9] = st_mode & S_IXOTH ? 'x' : '-';
	permissions[10] = get_xattr_or_acl(filename);
	if (st_mode & S_ISUID)
		permissions[3] = (st_mode & S_IXUSR) ? 's' : 'S';
	if (st_mode & S_ISGID)
		permissions[6] = (st_mode & S_IXGRP) ? 's' : 'S';
	if (st_mode & S_ISVTX)
		permissions[9] = (st_mode & S_IXOTH) ? 't' : 'T';
	return (permissions);
}
