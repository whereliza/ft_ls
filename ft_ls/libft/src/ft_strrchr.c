/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:53:12 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/23 16:29:43 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *cp;

	cp = (char *)str;
	while (*str)
		str++;
	while (str != cp && *str != (char)c)
		str--;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
