/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:39:08 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/18 12:09:30 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int c;

	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(max - min);
	c = min;
	while (min < max)
	{
		(*range)[min - c] = min;
		min++;
	}
	return (max - c);
}
