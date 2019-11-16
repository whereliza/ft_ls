/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output_multi_column.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:15:27 by clothor-          #+#    #+#             */
/*   Updated: 2019/09/18 18:51:43 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_mc_list_stats(t_list *list, int col, t_mc_list *mc_list)
{
	mc_list->max = get_max_filename_length(list);
	mc_list->lm = get_lm(mc_list->max);
	mc_list->columns = (col - 1) / mc_list->lm;
	mc_list->columns = mc_list->columns == 0 ? 1 : mc_list->columns;
	mc_list->lst_len = ft_lstlen(list);
	mc_list->rows = mc_list->lst_len / mc_list->columns +
		((mc_list->lst_len % mc_list->columns) != 0);
}

void	print_multi_column_list(t_list *list, char *flags, t_mc_list *mc_list)
{
	t_list	*node;
	t_list	*first;
	int		i;
	int		c;

	c = 0;
	first = list;
	node = first;
	while (c < mc_list->lst_len)
	{
		if (flags && flags[10] == 'G')
			set_output_color(((t_f_stat*)(node->content))->file_type);
		ft_putstr_w(((t_f_stat*)(node->content))->name, mc_list->max, 1);
		ft_putchar('\t');
		i = -1;
		while (node && ++i < mc_list->rows)
			node = node->next;
		if (!node)
		{
			node = first->next;
			first = node;
			ft_putendl("");
		}
		c++;
	}
}

void	print_multi_column_dlist(t_list *dlist, char *flags, int col,
		int unique_dir)
{
	t_list		*dnode;
	t_mc_list	mc_list;

	dnode = dlist;
	while (dnode)
	{
		if (!unique_dir)
		{
			if (dnode != dlist)
				ft_putendl("");
			ft_putstr((((t_dnode*)(dnode->content))->dir_stats)->path);
			ft_putendl(":");
		}
		if ((((t_dnode*)(dnode->content))->dir_stats)->permissions[1] == '-')
		{
			set_errno_to_nopermission((((t_dnode*)(dnode->content))->
						dir_stats)->path);
			ft_perror((((t_dnode*)(dnode->content))->dir_stats)->name);
		}
		get_mc_list_stats(((t_dnode*)(dnode->content))->f_list, col, &mc_list);
		print_multi_column_list(((t_dnode*)(dnode->content))->f_list, flags,
				&mc_list);
		dnode = dnode->next;
	}
}

void	print_multi_column(t_wlists *wlists, char *flags)
{
	int			unique_dir;
	int			col;
	t_mc_list	mc_list;

	col = get_terminal_width();
	print_nonexistent(wlists->nonexistent_list);
	if (wlists->file_list)
	{
		get_mc_list_stats(wlists->file_list, col, &mc_list);
		print_multi_column_list(wlists->file_list, flags, &mc_list);
	}
	if (wlists->file_list && wlists->dir_list)
		ft_putendl("");
	unique_dir = ft_lstlen(wlists->file_list) == 0 &&
		ft_lstlen(wlists->dir_list) == 1 &&
		ft_lstlen(wlists->nonexistent_list) == 0;
	print_multi_column_dlist(wlists->dir_list, flags, col, unique_dir);
}
