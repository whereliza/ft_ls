/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:24:23 by clothor-          #+#    #+#             */
/*   Updated: 2019/11/10 18:43:09 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_filename(char *path)
{
	int i;

	i = ft_strlen(path) - 1;
	while (i >= 0 && path[i] != '/')
		i--;
	return (path + i + 1);
}

void	process_recursivity(t_wlists *wlists, char *flags)
{
	int unique_dir;

	unique_dir = ft_lstlen(wlists->file_list) == 0 &&
		ft_lstlen(wlists->dir_list) == 1 &&
		ft_lstlen(wlists->nonexistent_list) == 0;
	sort(wlists, flags);
	if (flags && flags[0] == 'R')
	{
		if (unique_dir)
		{
			print_stats(wlists, flags);
			single_stream_recursion(((t_dnode*)(wlists->dir_list->
							content))->f_list, flags);
		}
		else
			multi_stream_recursion(wlists, flags);
	}
	else
		print_stats(wlists, flags);
}

void	process(char ***files, char **flags)
{
	int			i;
	t_wlists	wlists;
	t_list		*new_node;

	init_wlists(&wlists);
	i = -1;
	while ((*files)[++i])
	{
		if (is_dir((*files)[i]))
			process_dir((*files)[i], *flags, &wlists);
		else if ((new_node = get_file_stat((*files)[i], *flags, 1)))
		{
			if (is_nonexistent(new_node))
				ft_lstappend(&(wlists.nonexistent_list), new_node);
			else
				ft_lstappend(&(wlists.file_list), new_node);
		}
	}
	process_recursivity(&wlists, *flags);
	free_wlists(&wlists);
}
