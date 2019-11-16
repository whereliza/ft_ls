/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:31:23 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/27 21:25:10 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char *)str);
	while (*str && len)
	{
		while (str[j] == find[j] && j < len)
		{
			if (find[++j] == '\0')
				return ((char *)str);
		}
		j = 0;
		str++;
		len--;
	}
	return (NULL);
}
