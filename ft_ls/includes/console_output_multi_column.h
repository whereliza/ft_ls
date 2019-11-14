/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output_multi_column.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:17:12 by gpop              #+#    #+#             */
/*   Updated: 2018/02/15 19:03:35 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_OUTPUT_MULTI_COLUMN_H
# define CONSOLE_OUTPUT_MULTI_COLUMN_H

# include "libft.h"
# include "file_obj.h"
# include "utils.h"
# include "console_output.h"
# include "console_utils.h"

typedef struct	s_mc_list
{
	int			columns;
	int			rows;
	int			lst_len;
	int			lm;
	int			max;
}				t_mc_list;

void			print_multi_column(t_wlists *wlists, char *flags);
void			print_multi_column_dlist(t_list *dlist, char *flags, int col,
		int unique_dir);

#endif
