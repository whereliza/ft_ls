/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:13:21 by clothor-          #+#    #+#             */
/*   Updated: 2019/09/19 18:48:33 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console_utils.h"

void	fill_file_size_width(t_list *node, t_c_widths *cwidths)
{
	int len;

	if (((t_f_stat*)(node->content))->file_type == 'b' ||
			((t_f_stat*)(node->content))->file_type == 'c')
	{
		if ((len = ft_intlen(((t_f_stat*)(node->content))->minor)) >
				cwidths->fs_width)
			cwidths->fs_width = len;
		if ((len = ft_intlen(((t_f_stat*)(node->content))->major)) >
				cwidths->longest_major)
			cwidths->longest_major = len;
	}
	else if ((len = ft_intlen(((t_f_stat*)(node->content))->file_size)) >
			cwidths->fs_width)
		cwidths->fs_width = len;
}

void	fill_c_widths(t_list *f_list, t_c_widths *cwidths)
{
	t_list	*node;
	int		len;

	cwidths->lc_width = 0;
	cwidths->uid_width = 0;
	cwidths->group_width = 0;
	cwidths->fs_width = 0;
	cwidths->longest_major = 0;
	node = f_list;
	while (node)
	{
		if ((len = ft_intlen(((t_f_stat*)(node->content))->link_count)) >
				cwidths->lc_width)
			cwidths->lc_width = len;
		if ((len = (int)ft_strlen(((t_f_stat*)(node->content))->user)) >
				cwidths->uid_width)
			cwidths->uid_width = len;
		if ((len = (int)ft_strlen(((t_f_stat*)(node->content))->group)) >
				cwidths->group_width)
			cwidths->group_width = len;
		fill_file_size_width(node, cwidths);
		node = node->next;
	}
}

void	print_nonexistent(t_list *list)
{
	t_list *node;

	node = list;
	if (node)
		set_errno_to_nsfod(((t_f_stat*)(node->content))->name);
	while (node)
	{
		ft_perror(((t_f_stat*)(node->content))->name);
		node = node->next;
	}
}

void	ft_perror(char *str)
{
	char *errmsg;

	errmsg = ft_strjoin("ft_ls: ", str);
	perror(errmsg);
	ft_strdel(&errmsg);
}
