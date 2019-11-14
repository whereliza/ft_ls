/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:29:57 by gpop              #+#    #+#             */
/*   Updated: 2018/02/15 19:00:17 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_H
# define CONSOLE_H

# include "file_obj.h"
# include "file_or_dir_validator.h"
# include "controller.h"
# include "error.h"
# include "console_output.h"
# include "console_output_multi_column.h"

void print_stats(t_wlists *wlists, char *flags);
void print_dir_content(t_list *dir_list, int format, int with_title,
		char *flags);

#endif
