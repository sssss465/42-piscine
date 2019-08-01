/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:51:33 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/13 15:33:07 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printlog(int i, int j, int x, int y)
{
	if ((i == 0 && j == 0) || (i == (y - 1) && j == (x - 1) && i > 0 && j > 0))
	{
		ft_putchar('/');
	}
	else if ((i == 0 && j == (x - 1)) || (i == (y - 1) && j == 0))
	{
		ft_putchar('\\');
	}
	else if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

int		rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printlog(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
