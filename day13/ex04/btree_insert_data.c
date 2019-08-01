/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:22:18 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/25 17:09:00 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void *))
{
	t_btree *t;

	t = *root;
	if (t == 0)
	{
		t = btree_create_node(item);
		return ;
	}
	if ((*cmpf)(item, t->item) < 0)
		btree_insert_data(&(t->left), item, cmpf);
	else
		btree_insert_data(&(t->right), item, cmpf);
}
