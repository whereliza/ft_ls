/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:48:57 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/26 18:34:03 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_itoa_len(int n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_itoa_len(n);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	if (n < 0)
		ret[i++] = '-';
	ret[len] = '\0';
	while (len-- > i)
	{
		ret[len] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (ret);
}
