/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:54:40 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/11/05 16:54:13 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_invalid_flag(char *flags)
{
	int i;

	if (!flags || flags[1] == '\0')
		return (0);
	i = 1;
	while (flags[i] != '\0')
	{
		if (flags[i] != 'r' && flags[i] != 'a' && flags[i] != 'R' &&
			flags[i] != 'l' && flags[i] != 't' && flags[i] != 'g' &&
			flags[i] != 'o' && flags[i] != '1' && flags[i] != 'A' &&
			flags[i] != 'S')
			return (flags[i]);
		i++;
	}
	return (0);
}

void	exit_with_err(char *err_msg, char ***file_list, char **flags)
{
	if (err_msg)
		ft_putendl(err_msg);
	free_input(file_list, flags);
	exit(EXIT_FAILURE);
}

void	display_usage_err(char *invalid_flag_args)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(get_invalid_flag(invalid_flag_args));
	ft_putchar('\n');
	ft_putendl(ERR_USAGE);
}

void	set_errno_to_nsfod(char *filename)
{
	struct stat file_info;

	lstat(filename, &file_info);
}

void	set_errno_to_nopermission(char *dirname)
{
	DIR *dir_p;

	dir_p = opendir(dirname);
}
