/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:02:24 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/10 12:02:25 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_help(int arr[3], int on)
{
	int i;
	int j;

	if (on > 2)
	{
		j = 0;
		while (j < 3)
		{
			ft_putchar('0' + arr[j]);
			j += 1;
		}
		if (!(arr[0] == 7 && arr[1] == 8 && arr[2] == 9))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	i = (on == 0) ? 0 : arr[on - 1] + 1;
	while (i <= 9)
	{
		arr[on] = i;
		ft_help(arr, on + 1);
		i = i + 1;
	}
}

void	ft_print_comb(void)
{
	int arr[3];

	ft_help(arr, 0);
}
