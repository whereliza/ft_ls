/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:16:01 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/10/15 18:52:39 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_lookthrough(t_f_stat *dir, char *flags)
{
	t_wlists	wlists;
	t_list		*new_node;
	t_dnode		*new_dnode;

	init_wlists(&wlists);
	new_node = get_dir_stat(dir->path, flags);
	if ((new_dnode = (t_dnode*)malloc(sizeof(t_dnode))))
	{
		create_and_append_dnode(new_dnode, new_node, &wlists, dir);
		sort(&wlists, flags);
		ft_putendl("");
		if (flags && (flags[2] == 'l' || flags[5] == 'g' || flags[6] == 'o'))
			print_dir_content(wlists.dir_list, 1, 1, flags);
		else if ((flags && flags[7] == '1') || !isatty(1))
			print_dir_content(wlists.dir_list, 0, 1, flags);
		else
			print_multi_column_dlist(wlists.dir_list, flags,
					get_terminal_width(), 0);
		single_stream_recursion(new_dnode->f_list, flags);
	}
	free_wlists(&wlists);
}

void	single_stream_recursion(t_list *flist, char *flags)
{
	while (flist)
	{
		if (((t_f_stat*)(flist->content))->file_type == 'd')
		{
			if (!flags || flags[1] != 'a' ||
				(!ft_strequ(((t_f_stat*)(flist->content))->name, ".") &&
				!ft_strequ(((t_f_stat*)(flist->content))->name, "..")))
				recursive_lookthrough(((t_f_stat*)(flist->content)), flags);
			flist->content = NULL;
		}
		flist = flist->next;
	}
}

void	multi_stream_recursion(t_wlists *wlists, char *flags)
{
	t_list *new_node;

	new_node = wlists->dir_list;
	wlists->dir_list = NULL;
	print_stats(wlists, flags);
	while (new_node)
	{
		recursive_lookthrough(((t_dnode*)(new_node->content))->dir_stats,
				flags);
		((t_dnode*)(new_node->content))->dir_stats = NULL;
		new_node = new_node->next;
	}
}
