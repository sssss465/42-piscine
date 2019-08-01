/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:26:39 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/24 11:41:09 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *c;
	t_list *p;
	t_list *n;

	c = *begin_list;
	p = NULL;
	while (c)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	*begin_list = p;
}
