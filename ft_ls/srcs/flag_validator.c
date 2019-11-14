/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:36:46 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/11/15 16:53:13 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flag_validator.h"

int	has_flags_only(char **argv, int argc)
{
	int i;

	if (argc <= 1)
		return (0);
	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	if (i == argc)
		return (1);
	return (0);
}

int	valid_flags(char *flags)
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
			flags[i] != 'S' && flags[i] != 'G')
			return (0);
		i++;
	}
	return (1);
}
