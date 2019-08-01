/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:58:32 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/11 18:01:43 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int res1;
	int res2;

	res1 = (*a) / (*b);
	res2 = (*a) % (*b);
	*a = res1;
	*b = res2;
}
