/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:35:16 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/05 01:51:11 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wc(char const *s, char c)
{
	size_t		wc;

	wc = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			wc++;
		while (*s && *s != c)
			s++;
	}
	return (wc);
}

static char		**ft_splitfree(char **s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s || (!(ret = (char **)malloc(sizeof(char *) * (wc(s, c) + 1)))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			if (!(ret[j++] = ft_strsub(s, i, len)))
				return (ft_splitfree(ret, j - 1));
			i += len;
		}
	}
	ret[j] = NULL;
	return (ret);
}
