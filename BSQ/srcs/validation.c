/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:02:07 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 16:44:58 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"

int		is_dig(char c)
{
	return (c >= '0' && c <= '9');
}

int		first_line_valid(char *str)
{
	char	dict[257];
	int		i;

	i = 0;
	while (i < 257)
		dict[i++] = 0;
	i = 0;
	while (is_dig(str[i]))
		i++;
	while (str[i] != '\n')
	{
		if (dict[(int)str[i] - '0']++)
			return (0);
		i++;
	}
	i -= 4;
	if (i < 0)
		return (0);
	return (1);
}

int		count_rows(char *str)
{
	int		lines;

	lines = 0;
	while (*str != '\n')
		str++;
	str++;
	while (*str != '\0')
		lines += (*str++ == '\n');
	return (lines);
}

int		all_lines_same_width(char *str)
{
	int		width;
	int		i;
	int		c;

	width = get_width_count(str);
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		c = 0;
		while (str[c + i] != '\n')
		{
			c++;
		}
		if (c != width)
			return (0);
		i += c + 1;
	}
	return (1);
}
