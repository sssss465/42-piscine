/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:48:16 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 15:57:36 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"
#include "bsq.h"

void	print_board(int **b, int x, int y)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			c = (b[i][j] + '0');
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	disp_board(int **b, int x, int y, char *str)
{
	int		i;
	int		j;
	char	chars[3];

	i = 0;
	chars[0] = get_empty_char(str);
	chars[1] = get_obs_char(str);
	chars[2] = get_full_char(str);
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (b[i][j] == 0)
				write(1, &chars[0], 1);
			if (b[i][j] == 1)
				write(1, &chars[1], 1);
			if (b[i][j] == 2)
				write(1, &chars[2], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	mod_board(int **b, int x, int y)
{
	int		*vals;
	int		i;
	int		j;

	vals = bsq(b, x, y);
	i = vals[0] - (vals[2] - 1);
	while (i <= vals[0])
	{
		j = vals[1] - (vals[2] - 1);
		while (j <= vals[1])
		{
			b[i][j] = 2;
			j++;
		}
		i++;
	}
	return ;
}
