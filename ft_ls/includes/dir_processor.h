/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_processor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:46:09 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:53:16 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIR_PROCESSOR_H
# define DIR_PROCESSOR_H

# include "libft.h"
# include "file_obj.h"
# include "wizard.h"

void	process_dir(char *dirpath, char *flags, t_wlists *wlists);
void	create_and_append_dnode(t_dnode *new_dnode, t_list *new_node,
		t_wlists *wlists, t_f_stat *dir);

#endif
