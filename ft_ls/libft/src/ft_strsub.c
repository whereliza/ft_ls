/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:51:05 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/24 20:19:34 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!(ret = (char *)malloc(len + 1)) || !s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i++] = s[start++];
	}
	ret[i] = '\0';
	return (ret);
}
