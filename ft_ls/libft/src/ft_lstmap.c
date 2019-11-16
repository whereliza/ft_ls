/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:13:40 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/11 20:24:50 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_free(t_list *lst)
{
	while (lst)
	{
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (!lst || !f || !(new = f(lst)))
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			return (ft_lstmap_free(tmp));
		}
		new = new->next;
	}
	return (tmp);
}
