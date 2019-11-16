/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:58:07 by clothor-          #+#    #+#             */
/*   Updated: 2018/12/05 06:25:53 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long		mod;
	long		nbr;
	const char	*tmp;

	mod = 1;
	nbr = 0;
	while (*str == ' ' || ('\a' <= *str && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	while (*str == '0')
		str++;
	tmp = str;
	while ('0' <= *str && *str <= '9')
		nbr = nbr * 10 + (*str++ - '0');
	nbr = mod * (nbr - 1) + mod;
	if (nbr * mod < 0 || (str - tmp) > 19)
		return (mod == 1 ? -1 : 0);
	return (nbr);
}
