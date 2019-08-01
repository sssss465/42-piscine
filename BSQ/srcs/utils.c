/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:02 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 11:46:32 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"

int		ft_min(int a, int b)
{
	return (a > b) ? b : a;
}

int		ft_min2(int a, int b, int c)
{
	return (ft_min(ft_min(a, b), c));
}

int		ft_tena(int cs, int c1, int c2)
{
	if (cs)
		return (c1);
	return (c2);
}

int		ft_max(int a, int b)
{
	return (a > b) ? a : b;
}

void	ft_putchar(char *s)
{
	while (*s)
	{
		write(1, s++, 1);
	}
}
