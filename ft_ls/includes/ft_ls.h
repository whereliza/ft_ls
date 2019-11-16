# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_ls.h                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clothor- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 19:30:39 by clothor-          #+#    #+#              #
#    Updated: 2018/12/04 22:02:58 by clothor-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>

# define SEC_IN_SIX_MONTHS 15778463
# define ERR_USAGE "usage: ft_ls [-1AGSRaglort] [file ...]"

# define BLU   "\x1B[34m"
# define RED   "\x1B[31m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define GRN   "\x1B[32m"
# define MAG   "\x1B[35m"
# define YEL   "\x1B[33m"
# define RESET "\x1B[0m"


typedef struct		s_f_stat
{
	char			*name;
	char			*path;
	char			file_type;
	char			*link;
	char			*permissions;
	long			link_count;
	char			*user;
	char			*group;
	unsigned int	minor;
	unsigned int	major;
	long long		file_size;
	long long		blocks_allocated;
	time_t			last_modification;
}					t_f_stat;

typedef struct		s_dnode
{
	t_f_stat		*dir_stats;
	t_list			*f_list;
}					t_dnode;

typedef struct		s_wlists
{
	t_list			*dir_list;
	t_list			*file_list;
	t_list			*nonexistent_list;
}					t_wlists;

typedef struct	s_mc_list
{
	int			columns;
	int			rows;
	int			lst_len;
	int			lm;
	int			max;
}				t_mc_list;

typedef struct	s_c_widths
{
	int			lc_width;
	int			uid_width;
	int			group_width;
	int			fs_width;
	int			longest_major;
}				t_c_widths;

void				free_dnode_list(t_list **list);
void				free_file_obj(t_f_stat **file_stat);
void				free_wlists(t_wlists *wlists);
int			fill_file_stat(t_f_stat **file_stat, struct stat file_info);
void		init_wlists(t_wlists *wlists);
t_f_stat	*new_file_stat(char *path, char *name);
void	fill_filelist(char ***file_list, char **flags, char **argv, int argc);
int		fill_flistwithcurrent(char ***file_list);
int	is_dir(char *filename);
int	is_hidden(char *filename);
int	is_nonexistent(t_list *node);
void	fill_flag_list(char **flags, char **argv);
void	check_sort_flags(char **flags, char c);
void	check_display_flags(char **flags, char c);
void	free_input(char ***file_list, char **flags);
int	has_flags_only(char **argv, int argc);
int	valid_flags(char *flags);

void print_total(t_list *f_list);
void print_formatted_list(t_list *list, t_c_widths *cwidths, char *flags);
void print_stats(t_wlists *wlists, char *flags);
void print_dir_content(t_list *dir_list, int format, int with_title,
					   char *flags);
void set_output_color(char file_type);
void			print_multi_column(t_wlists *wlists, char *flags);
void			print_multi_column_dlist(t_list *dlist, char *flags, int col,
										 int unique_dir);

void			fill_c_widths(t_list *f_list, t_c_widths *cwidths);
void			print_nonexistent(t_list *list);
void			ft_perror(char *str);
void	process(char ***files, char **flags);
char	*get_filename(char *path);
char *get_file_permissions(mode_t st_mode, char *filename);
void recursive_lookthrough(t_f_stat *dir, char *flags);
void single_stream_recursion(t_list *flist, char *flags);
void multi_stream_recursion(t_wlists *wlists, char *flags);
void	sort_w_list(t_list **list, int ascending,
					int (*cmp)(t_list *, t_list *, int, int), int is_dir);
void	sort(t_wlists *wlists, char *flags);
int compare_name(t_list *node1, t_list *node2, int ascending, int is_dir);
int compare_time(t_list *node1, t_list *node2, int ascending, int is_dir);
int compare_size(t_list *node1, t_list *node2, int ascending, int is_dir);
int get_terminal_width();
int get_max_filename_length(t_list *list);
int get_lm(int n);
t_list	*get_file_stat(char *filename, char *flags, int isarg);
t_list	*get_dir_stat(char *dirname, char *flags);
char	*append_path(char *firstpath, char *secondpath);
void	process_dir(char *dirpath, char *flags, t_wlists *wlists);
void	create_and_append_dnode(t_dnode *new_dnode, t_list *new_node,
								t_wlists *wlists, t_f_stat *dir);
void	exit_with_err(char *err_msg, char ***file_list, char **flags);
void	display_usage_err(char *invalid_flag_args);
void	set_errno_to_nsfod(char *filename);
void	set_errno_to_nopermission(char *dirname);

#endif
