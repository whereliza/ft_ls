/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:53:17 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/23 23:39:20 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *cur;

	if (!(cur = (size_t*)malloc(size)))
		return (NULL);
	cur = ft_memset(cur, 0, size);
	return (cur);
}
