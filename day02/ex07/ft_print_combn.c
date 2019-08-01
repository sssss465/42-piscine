/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:24:52 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/10 20:24:54 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_cm(int sum, int nlast)
{
	if (sum != nlast)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_help(int *arr, int on, int n, int nlast)
{
	int i;
	int j;
	int s;

	if (on > n - 1)
	{
		j = 0;
		s = 0;
		while (j < n)
		{
			ft_putchar('0' + arr[j]);
			s += arr[j];
			j += 1;
		}
		ft_print_cm(s, nlast);
		return ;
	}
	i = (on == 0) ? 0 : arr[on - 1] + 1;
	while (i <= 9)
	{
		arr[on] = i;
		ft_help(arr, on + 1, n, nlast);
		i = i + 1;
	}
}

void	ft_print_combn(int n)
{
	int arr[11];
	int nlast;
	int count;

	nlast = 0;
	count = 0;
	while (count < n)
	{
		nlast += 9 - count;
		count++;
	}
	ft_help(arr, 0, n, nlast);
}
