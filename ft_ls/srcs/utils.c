/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:57:29 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/11/06 18:47:41 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_terminal_width(void)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int	get_max_filename_length(t_list *list)
{
	int		len;
	int		max_len;
	t_list	*node;

	max_len = 0;
	node = list;
	while (node)
	{
		if ((len = ft_strlen(((t_f_stat*)(node->content))->name)) > max_len)
			max_len = len;
		node = node->next;
	}
	return (max_len);
}

int	get_lm(int n)
{
	int lowest_multiple;

	lowest_multiple = 0;
	while (lowest_multiple <= n)
		lowest_multiple += 8;
	return (lowest_multiple);
}
