/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:05:43 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/16 16:45:35 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcapitalize(char *str)
{
	int i;
	int cap;

	i = 0;
	cap = 1;
	while (str[i] != '\0')
	{
		if (cap)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 'a' - 'A';
			cap = 0;
		}
		else if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
			cap = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a' - 'A';
		i++;
	}
	return (str);
}
