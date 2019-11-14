/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:55:23 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:53:53 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "input_destroy.h"

# define ERR_USAGE "usage: ft_ls [-1AGSRaglort] [file ...]"

void	exit_with_err(char *err_msg, char ***file_list, char **flags);
void	display_usage_err(char *invalid_flag_args);
void	set_errno_to_nsfod(char *filename);
void	set_errno_to_nopermission(char *dirname);

#endif
