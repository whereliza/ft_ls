/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 04:40:03 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/03 05:37:19 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordccount(const char *str, char c)
{
	size_t wc;

	wc = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			wc++;
		while (*str && *str != c)
			str++;
	}
	return (wc);
}
