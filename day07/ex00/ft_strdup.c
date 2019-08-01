/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:39:17 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/17 17:02:31 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		n;
	int		i;
	char	*out;

	n = 0;
	i = 0;
	while (src[n++] != '\0')
		;
	out = malloc(n);
	while (i < n)
	{
		out[i] = src[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
