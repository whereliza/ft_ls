/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 22:25:08 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:52:34 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "flag_validator.h"
# include "error.h"
# include "wizard.h"
# include "file_obj.h"
# include "console.h"
# include "sort.h"
# include "dir_processor.h"
# include "recursion.h"

void	process(char ***files, char **flags);
char	*get_filename(char *path);

#endif
