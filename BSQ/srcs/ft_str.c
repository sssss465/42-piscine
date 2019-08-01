/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:21:01 by jfan              #+#    #+#             */
/*   Updated: 2019/07/31 12:21:16 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"

int		ft_strlen(char *str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int		ft_strnline(char *str)
{
	int		counter;

	counter = 0;
	while (str[counter] != '\n')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strip(char *str, char r)
{
	char	*dst;
	char	*p;

	dst = malloc(sizeof(char) * ft_strlen(str));
	p = dst;
	while (*str != '\0')
	{
		if (*str != r)
		{
			*p = *str;
			p++;
		}
		str++;
	}
	*p = '\0';
	return (dst);
}
