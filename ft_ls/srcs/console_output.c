/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorrupt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 08:03:21 by fcorrupt          #+#    #+#             */
/*   Updated: 2019/09/15 18:50:38 by fcorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_total(t_list *f_list)
{
	int total;

	if (!f_list)
		return ;
	total = 0;
	while (f_list)
	{
		total += ((t_f_stat*)(f_list->content))->blocks_allocated;
		f_list = f_list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putendl("");
}

void	print_l_modif(time_t lm)
{
	char	*str;
	time_t	ct;

	if (!(str = ft_strnew(24)))
		return ;
	if (!(str = ft_strdup(ctime(&lm))))
		return ;
	ct = time(0);
	if (ft_abs(ct - lm) > SEC_IN_SIX_MONTHS)
	{
		str[11] = '\0';
		str[24] = '\0';
		ft_putstr(str + 4);
		ft_putstr(str + 19);
	}
	else
	{
		str[16] = '\0';
		ft_putstr(str + 4);
	}
	ft_strdel(&str);
}

void	print_file_size(t_f_stat *f_stat, t_c_widths *cwidths)
{
	if (f_stat->file_type == 'b' || f_stat->file_type == 'c')
	{
		ft_putnbr_w(f_stat->major, ft_max(3, cwidths->longest_major));
		ft_putchar(',');
		ft_putnbr_w(f_stat->minor, ft_max(4, cwidths->fs_width));
	}
	else if (cwidths->longest_major != 0)
		ft_putnbr_w(f_stat->file_size, ft_max(4, cwidths->fs_width) +
				ft_max(3, cwidths->longest_major) + 1);
	else
		ft_putnbr_w(f_stat->file_size, cwidths->fs_width);
	ft_putstr(" ");
}

void	print_per_lc_usr_grp(t_f_stat *f_stat, t_c_widths *cwidths, char *flags)
{
	ft_putstr(f_stat->permissions);
	ft_putstr(" ");
	ft_putnbr_w(f_stat->link_count, cwidths->lc_width);
	ft_putstr(" ");
	if (!flags || flags[5] != 'g')
	{
		ft_putstr_w(f_stat->user, cwidths->uid_width, 1);
		ft_putstr("  ");
	}
	if (!flags || flags[6] != 'o')
	{
		ft_putstr_w(f_stat->group,
				cwidths->group_width, 1);
		ft_putstr("  ");
	}
	if (flags && flags[5] == 'g' && flags[6] == 'o')
		ft_putstr("  ");
}

void	print_formatted_list(t_list *list, t_c_widths *cwidths, char *flags)
{
	t_list	*node;

	node = list;
	while (node)
	{
		if (flags && flags[10] == 'G')
			set_output_color(((t_f_stat*)(node->content))->file_type);
		print_per_lc_usr_grp(((t_f_stat*)(node->content)), cwidths, flags);
		print_file_size(((t_f_stat*)(node->content)), cwidths);
		print_l_modif(((t_f_stat*)(node->content))->last_modification);
		ft_putstr(" ");
		ft_putstr(((t_f_stat*)(node->content))->name);
		if (((t_f_stat*)(node->content))->file_type == 'l')
		{
			ft_putstr(" -> ");
			ft_putstr(((t_f_stat*)(node->content))->link);
		}
		ft_putchar('\n');
		node = node->next;
	}
	if (flags && flags[10] == 'G')
		set_output_color('X');
}
