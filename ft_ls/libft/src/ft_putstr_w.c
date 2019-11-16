/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:33:10 by clothor-          #+#    #+#             */
/*   Updated: 2019/07/15 21:17:01 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_w(char *str, int width, int start)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(str);
	if (!start)
		while (i++ < width - len)
			ft_putchar(' ');
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	if (start)
		while (i++ < width)
			ft_putchar(' ');
}
