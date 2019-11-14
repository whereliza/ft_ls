/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:15 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 17:16:38 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECURSION_H
# define RECURSION_H

# include "file_obj.h"
# include "libft.h"
# include "console.h"
# include "console_output.h"
# include "wizard.h"
# include "dir_processor.h"
# include "utils.h"
# include "console_output_multi_column.h"

void recursive_lookthrough(t_f_stat *dir, char *flags);
void single_stream_recursion(t_list *flist, char *flags);
void multi_stream_recursion(t_wlists *wlists, char *flags);

#endif
