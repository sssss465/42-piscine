/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:28:04 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/18 15:41:19 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		n;
	int		slot;
	char	*out;

	i = 1;
	n = 0;
	while (i < argc)
		n += ft_strlen(argv[i++]);
	out = malloc(n + 1);
	i = 1;
	slot = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			out[slot++] = argv[i][j++];
		if (i != argc - 1)
			out[slot++] = '\n';
		i++;
	}
	out[slot] = '\0';
	return (out);
}
