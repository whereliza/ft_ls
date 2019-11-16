/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:48:44 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/21 22:51:59 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t n)
{
	const unsigned char *cdst;
	const unsigned char *csrc;

	cdst = (const unsigned char *)dst;
	csrc = (const unsigned char *)src;
	while (n--)
	{
		if (*cdst != *csrc)
			return (*cdst - *csrc);
		if (n)
		{
			cdst++;
			csrc++;
		}
	}
	return (0);
}
