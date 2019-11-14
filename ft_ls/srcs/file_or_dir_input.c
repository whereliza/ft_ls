/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_or_dir_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:29:48 by clothor-          #+#    #+#             */
/*   Updated: 2019/11/11 08:21:53 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_or_dir_input.h"

void	fill_filelist(char ***file_list, char **flags, char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	if (i < argc &&
			!(*file_list = (char**)malloc(sizeof(char*) * (argc - i) + 1)))
		exit_with_err("malloc error", file_list, flags);
	j = 0;
	while (i < argc)
	{
		if (!((*file_list)[j] = ft_strnew(ft_strlen(argv[i]))))
			exit_with_err("malloc error", file_list, flags);
		(*file_list)[j] = ft_strcpy((*file_list)[j], argv[i]);
		i++;
		j++;
	}
	(*file_list)[j] = NULL;
}

int		fill_flistwithcurrent(char ***file_list)
{
	if (!(*file_list = (char**)malloc(sizeof(char*) * 2)))
		return (-1);
	(*file_list)[0] = ft_strnew(1);
	if (!(*file_list[0]))
		return (-1);
	(*file_list)[0][0] = '.';
	(*file_list)[1] = NULL;
	return (0);
}
