/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor-  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:45:39 by clothor-          #+#    #+#             */
/*   Updated: 2019/11/11 18:45:55 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dir_processor.h"

void	process_dir(char *dirpath, char *flags, t_wlists *wlists)
{
	t_list	*new_node;
	t_dnode	*new_dnode;

	new_node = get_dir_stat(dirpath, flags);
	if ((new_dnode = (t_dnode*)malloc(sizeof(t_dnode))))
	{
		new_dnode->f_list = new_node;
		if ((new_node = get_file_stat(dirpath, flags, 1)))
		{
			new_dnode->dir_stats = (t_f_stat*)(new_node->content);
			free(new_node);
		}
		new_node = ft_lstnew(NULL, 0);
		new_node->content = new_dnode;
		new_node->content_size = sizeof(new_dnode);
		ft_lstappend(&(wlists->dir_list), new_node);
	}
}

void	create_and_append_dnode(t_dnode *new_dnode, t_list *new_node,
		t_wlists *wlists, t_f_stat *dir)
{
	new_dnode->f_list = new_node;
	new_dnode->dir_stats = dir;
	new_node = ft_lstnew(NULL, 0);
	new_node->content = new_dnode;
	new_node->content_size = sizeof(new_dnode);
	ft_lstappend(&(wlists->dir_list), new_node);
}
