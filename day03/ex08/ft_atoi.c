/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:07:30 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/12 12:00:41 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	if (str[0] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = (str[0] == '-') ? -res : res;
	return (res);
}
#include <stdio.h>
int main(){
	char arr[] = " -2147483647";
	char arr2[] = "823501";
	char arr3[] = "33";

	printf("%d\n", ft_atoi(arr3));

}