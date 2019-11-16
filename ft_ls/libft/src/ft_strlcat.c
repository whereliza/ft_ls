/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:28:54 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/27 17:45:10 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t ldst;
	size_t lsrc;

	j = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (size <= ldst)
		return (size + lsrc);
	while (src[j] != '\0' && ldst + j + 1 < size)
	{
		dst[ldst + j] = src[j];
		j++;
	}
	dst[ldst + j] = '\0';
	return (ldst + lsrc);
}
