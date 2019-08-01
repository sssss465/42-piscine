/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:33:34 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 16:30:57 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"

char	*ft_stringify(int fd)
{
	char	*s1;
	char	*s2;
	int		ret;

	s1 = (char*)malloc(sizeof(char));
	s1[0] = '\0';
	s2 = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(fd, s2, BUF_SIZE)))
	{
		s2[ret] = '\0';
		s1 = realloc_and_strcat(s1, s2);
	}
	free(s2);
	return (s1);
}

char	*realloc_and_strcat(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		ret[j++] = s1[i++];
	free(s1);
	i = 0;
	while (s2[i] != '\0')
		ret[j++] = s2[i++];
	ret[j] = '\0';
	return (ret);
}

int		is_valid_board(char *str)
{
	char e;
	char o;

	if (count_rows(str) < 1)
		return (0);
	if (count_rows(str) != get_row_count(str))
		return (0);
	if (!first_line_valid(str))
		return (0);
	e = get_empty_char(str);
	o = get_obs_char(str);
	if (!all_lines_same_width(str))
		return (0);
	return (1);
}

/*
** Takes destination board and string file and fills board, assumes valid board
*/

int		fill_board(int **b, char *str)
{
	int		i;
	int		j;
	char	*p;

	p = str;
	while (*p != '\n')
		p++;
	p = ft_strip(++p, '\n');
	i = 0;
	while (i < get_row_count(str))
	{
		j = 0;
		while (j < get_width_count(str))
		{
			if (p[i * get_width_count(str) + j] == get_empty_char(str))
				b[i][j] = 0;
			else if (p[i * get_width_count(str) + j] == get_obs_char(str))
				b[i][j] = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Takes fd and modifies board with values, return 1 if succesful, 0 otherwise
*/

char	*read_board(int ***b, int fd, int *x, int *y)
{
	char	*str;

	str = ft_stringify(fd);
	if (is_valid_board(str))
	{
		*b = build_arr(get_row_count(str), get_width_count(str));
		*x = get_row_count(str);
		*y = get_width_count(str);
		if (fill_board(*b, str))
			return (str);
	}
	return (NULL);
}
