/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:18:35 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/17 17:25:59 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *out;
	int c;

	if (min >= max)
		return (0);
	out = malloc(max - min);
	c = min;
	while (min < max)
	{
		out[min - c] = min;
		min++;
	}
	return (out);
}
