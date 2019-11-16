/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:56:44 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/05 20:57:12 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *cdst;
	unsigned char *csrc;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
