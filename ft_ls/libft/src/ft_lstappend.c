/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:43:24 by clothor-          #+#    #+#             */
/*   Updated: 2019/08/18 16:10:32 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = new;
		}
	}
}
