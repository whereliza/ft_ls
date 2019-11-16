/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 05:22:40 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/03 05:37:15 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *str)
{
	size_t state;
	size_t wc;

	wc = 0;
	state = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wc++;
		}
		str++;
	}
	return (wc);
}
