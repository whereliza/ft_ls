/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 08:54:38 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/11/01 08:54:46 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_destroy.h"

void	free_input(char ***file_list, char **flags)
{
	int i;

	i = 0;
	if (file_list && *file_list)
	{
		while ((*file_list)[i])
			free((*file_list)[i++]);
		free(*file_list);
		*file_list = NULL;
	}
	if (flags && *flags)
	{
		free(*flags);
		*flags = NULL;
	}
}
