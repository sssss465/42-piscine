/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:10:20 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/23 17:25:37 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *b;

	b = ft_create_elem(data);
	b->next = *begin_list;
	*begin_list = b;
}
