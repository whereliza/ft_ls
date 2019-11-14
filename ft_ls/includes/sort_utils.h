/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 18:14:05 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 19:01:16 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "libft.h"
# include "file_obj.h"
# include "controller.h"

int compare_name(t_list *node1, t_list *node2, int ascending, int is_dir);
int compare_time(t_list *node1, t_list *node2, int ascending, int is_dir);
int compare_size(t_list *node1, t_list *node2, int ascending, int is_dir);

#endif
