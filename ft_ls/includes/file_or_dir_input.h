/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_or_dir_input.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:26:46 by gpop              #+#    #+#             */
/*   Updated: 2018/02/14 18:57:27 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OR_DIR_INPUT_H
# define FILE_OR_DIR_INPUT_H

# include "error.h"
# include "libft.h"

void	fill_filelist(char ***file_list, char **flags, char **argv, int argc);
int		fill_flistwithcurrent(char ***file_list);

#endif
