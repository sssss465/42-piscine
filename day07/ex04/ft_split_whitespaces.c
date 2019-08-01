/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:38:47 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/18 16:57:38 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}

int		ft_words(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 1;
	while (str[i] != '\0')
	{
		words += (str[i] == '\t' || str[i] == ' ' || str[i] == '\n');
		i++;
	}
	return (words);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	int		old;
	char	**out;

	i = 0;
	j = 0;
	old = 0;
	out = malloc(sizeof(char *) * ft_words(str) + 1);
	while (i < ft_words(str))
	{
		old = j;
		while (str[j] != '\t' || str[j] != '\n' || str[j] != ' ')
			j++;
		out[i] = malloc(j - old);
		k = old;
		while (old < j)
		{
			out[i][old - k] = str[old];
			old++;
		}
		out[i++][old] = '\0';
		j++;
	}
	out[i] = 0;
	return (out);
}
