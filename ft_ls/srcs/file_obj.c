/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:32:13 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/10/15 08:40:58 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_obj.h"

void	free_file_obj(t_f_stat **file_stat)
{
	if (!file_stat || !(*file_stat))
		return ;
	if ((*file_stat)->name)
		ft_strdel(&((*file_stat)->name));
	if ((*file_stat)->path)
		ft_strdel(&((*file_stat)->path));
	if ((*file_stat)->link)
		ft_strdel(&((*file_stat)->link));
	if ((*file_stat)->user)
		ft_strdel(&((*file_stat)->user));
	if ((*file_stat)->group)
		ft_strdel(&((*file_stat)->group));
	free(*file_stat);
	*file_stat = NULL;
}

void	free_t_f_stat_list(t_list **list)
{
	t_list		*node;
	t_f_stat	*file_stat;
	t_list		*prev;

	node = *list;
	while (node)
	{
		file_stat = (t_f_stat*)(node->content);
		free_file_obj(&file_stat);
		prev = node;
		node = node->next;
		free(prev);
	}
	*list = NULL;
}

void	free_dnode_list(t_list **list)
{
	t_list	*main_node;
	t_dnode	*dnode;
	t_list	*prev;

	main_node = (*list);
	while (main_node)
	{
		dnode = ((t_dnode*)(main_node->content));
		free_t_f_stat_list(&(dnode->f_list));
		if (dnode->dir_stats)
			free_file_obj(&(dnode->dir_stats));
		prev = main_node;
		main_node = main_node->next;
		free(prev);
	}
	*list = NULL;
}

void	free_wlists(t_wlists *wlists)
{
	if (wlists->dir_list)
		free_dnode_list(&(wlists->dir_list));
	if (wlists->file_list)
		free_t_f_stat_list(&(wlists->file_list));
	if (wlists->nonexistent_list)
		free_t_f_stat_list(&(wlists->nonexistent_list));
}
