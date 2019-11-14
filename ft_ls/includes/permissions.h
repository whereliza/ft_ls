/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:21:41 by gpop              #+#    #+#             */
/*   Updated: 2018/02/04 16:21:53 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERMISSIONS_H
# define PERMISSIONS_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>

char *get_file_permissions(mode_t st_mode, char *filename);

#endif
