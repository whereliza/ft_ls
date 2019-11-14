/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:38:11 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 19:00:56 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"
# include "file_obj.h"
# include "sort_utils.h"
# include "controller.h"

void	sort_w_list(t_list **list, int ascending,
		int (*cmp)(t_list *, t_list *, int, int), int is_dir);
void	sort(t_wlists *wlists, char *flags);

#endif
