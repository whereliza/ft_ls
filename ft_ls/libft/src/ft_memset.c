/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:39:33 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/21 23:16:41 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char *cur;

	cur = (unsigned char *)dest;
	while (n--)
	{
		*cur++ = (unsigned char)c;
	}
	return (dest);
}
