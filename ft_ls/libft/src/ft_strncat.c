/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:54:50 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/22 22:25:04 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *cp;

	cp = dst;
	while (*cp)
		cp++;
	while (n--)
		if (!(*cp++ = *src++))
			return (dst);
	*cp = '\0';
	return (dst);
}
