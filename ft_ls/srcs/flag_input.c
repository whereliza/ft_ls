/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clothor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:28:38 by clothor-          #+#    #+#             */
/*   Updated: 2019/11/12 17:04:08 by clothor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_flag_arguments(char ***flag_arguments)
{
	int i;

	if (flag_arguments && *flag_arguments)
	{
		i = 0;
		while ((*flag_arguments)[i])
			ft_strdel((*flag_arguments) + (i++));
		free(*flag_arguments);
		*flag_arguments = NULL;
	}
	flag_arguments = NULL;
}

void	get_flag_arguments(char ***flag_arguments, char **argv)
{
	int i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	if (i == 1)
	{
		*flag_arguments = NULL;
		return ;
	}
	if (!(*flag_arguments = (char**)malloc(sizeof(char*) * i)))
		exit_with_err("malloc error", NULL, NULL);
	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (!((*flag_arguments)[i - 1] = ft_strnew(ft_strlen(argv[i]))))
		{
			free_flag_arguments(flag_arguments);
			exit_with_err("malloc error", NULL, NULL);
		}
		(*flag_arguments)[i - 1] = ft_strcpy((*flag_arguments)[i - 1], argv[i]);
		i++;
	}
	(*flag_arguments)[i - 1] = NULL;
}

void	clean_flag_list(char **dirty_flags)
{
	char	*clean_flags;
	int		i;

	if (!(clean_flags = ft_strnew(11)))
		exit_with_err("malloc error", NULL, dirty_flags);
	ft_memset((void*)clean_flags, '_', 11);
	i = 0;
	while ((*dirty_flags)[i])
	{
		check_sort_flags(&clean_flags, (*dirty_flags)[i]);
		check_display_flags(&clean_flags, (*dirty_flags)[i]);
		clean_flags[0] = (*dirty_flags)[i] == 'R' ? 'R' : clean_flags[0];
		i++;
	}
	ft_strdel(dirty_flags);
	*dirty_flags = clean_flags;
}

void	flag_args_to_flags(char ***flag_args, char **flags)
{
	int		i;
	char	*tmp;

	if (!(*flags = ft_strnew(0)))
	{
		free_flag_arguments(flag_args);
		exit_with_err("malloc error", NULL, NULL);
	}
	i = -1;
	while ((*flag_args)[++i])
		if (valid_flags((*flag_args)[i]))
		{
			tmp = ft_strjoin(*flags, (*flag_args)[i]);
			ft_strdel(flags);
			*flags = tmp;
		}
		else
		{
			display_usage_err((*flag_args)[i]);
			free_flag_arguments(flag_args);
			exit_with_err(NULL, NULL, flags);
		}
}

void	fill_flag_list(char **flags, char **argv)
{
	char	**flag_args;

	*flags = NULL;
	get_flag_arguments(&flag_args, argv);
	if (!flag_args)
		return ;
	flag_args_to_flags(&flag_args, flags);
	clean_flag_list(flags);
}
