/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wizard.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 22:58:21 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 19:01:37 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIZARD_H
# define WIZARD_H

# include "file_obj_create.h"
# include "file_obj.h"
# include "file_or_dir_validator.h"
# include "console.h"
# include "controller.h"
# include <dirent.h>

t_list	*get_file_stat(char *filename, char *flags, int isarg);
t_list	*get_dir_stat(char *dirname, char *flags);
char	*append_path(char *firstpath, char *secondpath);

#endif
