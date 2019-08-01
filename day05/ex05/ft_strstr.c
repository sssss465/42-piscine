/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:34:13 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/16 19:09:53 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int found;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		found = 1;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
			{
				found = 0;
				break ;
			}
			j++;
		}
		if (found && to_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
