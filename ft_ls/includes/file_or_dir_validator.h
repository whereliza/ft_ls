/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_or_dir_validator.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:16:23 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:58:14 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OR_DIR_VALIDATOR_H
# define FILE_OR_DIR_VALIDATOR_H

# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"
# include "file_obj.h"

int	is_dir(char *filename);
int	is_hidden(char *filename);
int	is_nonexistent(t_list *node);

#endif
