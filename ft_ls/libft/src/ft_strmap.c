/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:15:57 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/24 20:22:54 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;
	size_t	l;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	if (!(ret = (char *)malloc(l + 1)))
		return (NULL);
	i = 0;
	while (i < l)
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
