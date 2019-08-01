/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:26:13 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/24 10:37:42 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *b;

	b = ft_create_elem(data);
	b->next = *begin_list;
	*begin_list = b;
}

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list		*head;
	int			i;

	i = 0;
	head = NULL;
	while (i < ac)
	{
		ft_list_push_front(&head, av[i]);
		i++;
	}
	return (head);
}
