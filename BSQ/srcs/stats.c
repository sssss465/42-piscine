/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:54:27 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 10:02:44 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"

/*
** This file will be used to get some stats about the string version of board
** for error checking
*/

int		get_row_count(char *str)
{
	int index;
	int end;
	int	res;

	index = 0;
	res = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	end = index - 4;
	index = 0;
	while (index <= end)
	{
		res = (res * 10) + str[index] - '0';
		index++;
	}
	return (res);
}

int		get_width_count(char *str)
{
	int		index;
	int		width;

	index = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	width = ft_strnline(&str[index + 1]);
	return (width);
}

char	get_empty_char(char *str)
{
	int		index;
	char	empty_char;

	index = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	empty_char = str[index - 3];
	return (empty_char);
}

char	get_obs_char(char *str)
{
	int		index;
	char	obs_char;

	index = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	obs_char = str[index - 2];
	return (obs_char);
}

char	get_full_char(char *str)
{
	int		index;
	char	full_char;

	index = 0;
	while (str[index] != '\n')
	{
		index++;
	}
	full_char = str[index - 1];
	return (full_char);
}
