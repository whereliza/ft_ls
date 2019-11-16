/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:38:01 by clothor-          #+#    #+#             */
/*   Updated: 2019/10/11 11:38:30 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap(t_list *node1, t_list *node2)
{
	ft_swap_mem(&(node1->content), &(node2->content), sizeof(void*));
	ft_swap_mem(&(node1->content_size), &(node2->content_size), sizeof(size_t));
}

void	sort_w_list(t_list **list, int ascending,
		int (*cmp)(t_list *, t_list *, int, int), int is_dir)
{
	t_list *nodei;
	t_list *nodej;
	t_list *nodep;

	if (!list || !(*list) || !((*list)->next))
		return ;
	nodei = *list;
	while (nodei->next)
	{
		nodep = nodei;
		nodej = nodei->next;
		while (nodej)
		{
			if (!((*cmp)(nodep, nodej, ascending, is_dir)))
				nodep = nodej;
			nodej = nodej->next;
		}
		if (nodep != nodei)
			swap(nodei, nodep);
		nodei = nodei->next;
	}
}

void	sort(t_wlists *wlists, char *flags)
{
	int		ascending;
	int		(*cmp)(t_list *, t_list *, int, int);
	t_list	*node;

	ascending = flags && flags[3] == 'r' ? 0 : 1;
	cmp = flags && flags[4] == 't' ? &compare_time : &compare_name;
	cmp = flags && flags[9] == 'S' ? &compare_size : cmp;
	sort_w_list(&(wlists->nonexistent_list), 1, &compare_name, 0);
	sort_w_list(&(wlists->file_list), ascending, cmp, 0);
	sort_w_list(&(wlists->dir_list), ascending, cmp, 1);
	node = wlists->dir_list;
	while (node)
	{
		sort_w_list(&(((t_dnode *)(node->content))->f_list), ascending, cmp, 0);
		node = node->next;
	}
}
