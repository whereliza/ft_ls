/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_output_color.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:44:23 by gpop              #+#    #+#             */
/*   Updated: 2018/02/15 19:03:57 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_OUTPUT_COLOR_H
# define CONSOLE_OUTPUT_COLOR_H

# include "libft.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

void set_output_color(char file_type);

#endif
