/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:28:39 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/23 23:40:14 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char *)malloc(size + 1)))
	{
		return (NULL);
	}
	ret = ft_memset(ret, '\0', size + 1);
	return (ret);
}
