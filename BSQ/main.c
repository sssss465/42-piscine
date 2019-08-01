/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfan <jfan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:23:42 by andhuang          #+#    #+#             */
/*   Updated: 2019/08/01 14:32:38 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"
#include "bsq.h"

void	read_stdinput(void)
{
	int		**arr;
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = 0;
	arr = NULL;
	if ((str = read_board(&arr, 0, &x, &y)))
	{
		mod_board(arr, x, y);
		disp_board(arr, x, y, str);
	}
	else
		write(2, "map error\n", 11);
}

void	print_break(int i, int argc)
{
	if (i != argc)
	{
		write(1, "\n", 2);
	}
}

int		main(int argc, char **argv)
{
	int		**arr;
	int		fd;
	int		i;
	int		xy[2];
	char	*str;

	arr = NULL;
	i = 1;
	while (argc > 1 && i < argc)
	{
		if ((fd = open(argv[i++], O_RDONLY)) < 0)
			write(2, "map error\n", 11);
		if (fd < 0)
			continue;
		if ((str = read_board(&arr, fd, &xy[0], &xy[1])))
		{
			mod_board(arr, xy[0], xy[1]);
			disp_board(arr, xy[0], xy[1], str);
		}
		else
			write(2, "map error\n", 11);
		print_break(i, argc);
	}
	if (argc <= 1)
		read_stdinput();
}
