/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:44:07 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/09/16 19:16:08 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_output_color(char file_type)
{
	if (file_type == 'X')
		ft_putstr(RESET);
	else if (file_type == 'l')
		ft_putstr(RED);
	else if (file_type == '-')
		ft_putstr(GRN);
	else if (file_type == 'c')
		ft_putstr(YEL);
	else if (file_type == 'b')
		ft_putstr(BLU);
	else if (file_type == 'd')
		ft_putstr(MAG);
	else if (file_type == 's')
		ft_putstr(CYN);
	else
		ft_putstr(WHT);
}
