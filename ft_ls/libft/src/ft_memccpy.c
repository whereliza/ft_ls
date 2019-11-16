/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:25:08 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/23 22:52:34 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *cdst;
	unsigned char *csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n--)
	{
		*cdst++ = *csrc;
		if ((unsigned char)c == *csrc++)
			return (cdst);
	}
	return (NULL);
}
