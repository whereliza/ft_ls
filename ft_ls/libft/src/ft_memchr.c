/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:23:25 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/05 07:27:26 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *cstr;

	cstr = (unsigned char*)str;
	while (n--)
	{
		if ((unsigned char)*cstr == (unsigned char)c)
			return (cstr);
		cstr++;
	}
	return (NULL);
}
