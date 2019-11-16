/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:17:07 by clothor-          #+#    #+#             */
/*   Updated: 2018/11/21 23:07:54 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *mem;

	if (!(mem = (char*)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(mem, str);
	return (mem);
}
