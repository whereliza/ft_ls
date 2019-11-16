/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:58:46 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/11/09 08:53:51 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	char	**file_list;
	char	*flags;

	file_list = NULL;
	if (argc == 1)
	{
		if (fill_flistwithcurrent(&file_list) == -1)
			exit_with_err("malloc error", &file_list, &flags);
	}
	else
	{
		fill_flag_list(&flags, argv);
		if (has_flags_only(argv, argc))
		{
			if (fill_flistwithcurrent(&file_list) == -1)
				exit_with_err("malloc error", &file_list, &flags);
		}
		else
			fill_filelist(&file_list, &flags, argv, argc);
	}
	process(&file_list, &flags);
	free_input(&file_list, &flags);
	return (0);
}
