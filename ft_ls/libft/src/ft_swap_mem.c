/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:33:21 by clothor-          #+#    #+#             */
/*   Updated: 2019/07/02 20:11:10 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_mem(void *s1, void *s2, size_t size)
{
	unsigned char	*tmp;

	tmp = (unsigned char*)malloc(size * sizeof(unsigned char));
	if (tmp == NULL)
		return ;
	ft_memmove(tmp, s1, size);
	ft_memmove(s1, s2, size);
	ft_memmove(s2, tmp, size);
	free(tmp);
}
