/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:39:24 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/25 17:38:35 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	ft_help(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *), void **out)
{
	if (root == 0)
		return ;
	ft_help(root->left, data_ref, cmpf, out);
	if (cmpf(data_ref, root->item))
	{
		*out = root->item;
		return ;
	}
	ft_help(root->right, data_ref, cmpf, out);
}

void	*btree_search_item(t_btree *root, void *data_ref,
int (*cmpf)(void *, void *))
{
	void	**out;

	*out = 0;
	ft_help(root, data_ref, cmpf, out);
	return (*out);
}
