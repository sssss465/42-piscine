/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:07:21 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/12 13:53:53 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		partition(int *arr, int beg, int end)
{
	int x;
	int i;
	int j;

	x = arr[end];
	i = beg;
	j = beg;
	while (j < end)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[end]);
	return (i);
}

void	qsort(int *arr, int beg, int end)
{
	int p;

	if (beg < end)
	{
		p = partition(arr, beg, end);
		qsort(arr, beg, p - 1);
		qsort(arr, p + 1, end);
	}
}

void	ft_sort_integer_table(int *tab, int size)
{
	qsort(tab, 0, size - 1);
}
