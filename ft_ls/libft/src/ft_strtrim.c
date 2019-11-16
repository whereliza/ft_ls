/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:47:56 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/27 19:23:28 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	i = ft_strlen(s);
	if (i == 0)
		return (ft_strsub(s, 0, 0));
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0'))
	{
		i--;
	}
	ret = ft_strsub(s, 0, i + 1);
	return (ret);
}
