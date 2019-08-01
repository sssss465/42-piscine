/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:47:51 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/12 11:55:55 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char		temp;
	char		*head;
	char		*tail;

	tail = str;
	while (*tail != '\0')
	{
		tail++;
	}
	if (tail > str)
	{
		tail--;
	}
	head = str;
	while (head < tail)
	{
		temp = *head;
		*head = *tail;
		*tail = temp;
		head++;
		tail--;
	}
	return (str);
}
