/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 10:39:38 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/24 10:48:21 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *nxt;
	t_list *p;

	p = *begin_list;
	while (p)
	{
		nxt = p->next;
		p->next = NULL;
		p = nxt;
	}
	*begin_list = NULL;
}
