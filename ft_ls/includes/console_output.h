/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:03:40 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:50:48 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_OUTPUT_H
# define CONSOLE_OUTPUT_H

# include "file_obj.h"
# include <time.h>
# include "error.h"
# include "console_utils.h"
# include "console_output_color.h"

# define SEC_IN_SIX_MONTHS 15778463

void print_total(t_list *f_list);
void print_last_modification(time_t lm);
void print_formatted_list(t_list *list, t_c_widths *cwidths, char *flags);

#endif
