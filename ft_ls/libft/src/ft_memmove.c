/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:55:31 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/22 20:54:25 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *cdst;
	unsigned char *csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	if (cdst > csrc)
		while (n--)
			*(cdst + n) = *(csrc + n);
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
