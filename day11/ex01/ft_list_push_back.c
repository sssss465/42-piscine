/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:49:23 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/23 17:15:53 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *p;

	p = *begin_list;
	if (!p)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = ft_create_elem(data);
}
