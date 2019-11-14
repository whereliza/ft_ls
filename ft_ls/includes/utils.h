/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:57:43 by gpop              #+#    #+#             */
/*   Updated: 2018/02/15 17:57:56 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/ioctl.h>
# include "libft.h"
# include "file_obj.h"

int get_terminal_width();
int get_max_filename_length(t_list *list);
int get_lm(int n);

#endif
