/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:39:10 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/31 16:14:25 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "imports.h"
#include "bsq.h"

int		**build_arr(int x, int y)
{
	int		i;
	int		**res;

	i = 0;
	res = malloc(sizeof(int *) * x);
	while (i < x)
		res[i++] = malloc(sizeof(int) * y);
	return (res);
}

int		*build_res(int x, int y, int len)
{
	int		*arr;

	arr = malloc(sizeof(int) * 3);
	arr[0] = x;
	arr[1] = y;
	arr[2] = len;
	return (arr);
}

void	dpset(int arr[], int size)
{
	size--;
	while (size >= 0)
	{
		arr[size] = 0;
		size--;
	}
}

int		*bsq_help(int **arr, int x, int y, int temp)
{
	int		i;
	int		j;
	int		dp[y + 1];
	int		*res;
	int		prev;

	i = 0;
	prev = 0;
	dpset(dp, y + 1);
	res = build_res(0, 0, 0);
	while (++i <= x)
	{
		j = 0;
		while (++j <= y)
		{
			temp = dp[j];
			if (!arr[i - 1][j - 1])
				dp[j] = ft_min2(dp[j], dp[j - 1], prev) + 1;
			if (!arr[i - 1][j - 1] && dp[j] > res[2])
				res = build_res(i - 1, j - 1, dp[j]);
			dp[j] = (arr[i - 1][j - 1]) ? 0 : dp[j];
			prev = temp;
		}
	}
	return (res);
}

int		*bsq(int **arr, int x, int y)
{
	return (bsq_help(arr, x, y, 0));
}
