/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:12:37 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/26 21:48:50 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t i;

	i = 0;
	if (*find == '\0')
		return ((char *)str);
	while (*str)
	{
		while (str[i] == find[i])
		{
			i++;
			if (find[i] == '\0')
				return ((char *)str);
		}
		i = 0;
		str++;
	}
	return (NULL);
}
