/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imports.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:41:45 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 17:53:42 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPORTS_H
# define IMPORTS_H

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# define BUF_SIZE 100000

int		ft_min(int a, int b);
int		ft_min2(int a, int b, int c);
int		ft_tena(int cs, int a, int b);
int		ft_max(int a, int b);

void	print_board(int **b, int x, int y);
void	disp_board(int **b, int x, int y, char *str);
void	mod_board(int **b, int x, int y);

int		**build_arr(int x, int y);

/*
** reader
*/

char	*ft_stringify(int fd);
char	*realloc_and_strcat(char *s1, char *s2);
char	*read_board(int ***b, int fd, int *x, int *y);
int		is_valid_board(char *str);

/*
** Board stats
*/
int		get_row_count(char *str);
char	get_empty_char(char *str);
char	get_obs_char(char *str);
char	get_full_char(char *str);
int		get_width_count(char *str);

int		ft_strnline(char *str);
int		ft_strlen(char *str);
char	*ft_strip(char *str, char c);

/*
** validation.c
*/
int		count_rows(char *str);
int		all_lines_same_width(char *str);
int		first_line_valid(char *str);
int		is_dig(char c);

#endif
