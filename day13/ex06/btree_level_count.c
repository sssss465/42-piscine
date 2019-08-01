/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:20:56 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/25 18:02:19 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int l, int r)
{
	return ((l > r) ? l : r);
}

int		btree_level_count(t_btree *root)
{
	if (root == 0)
		return (0);
	return (1 + ft_max(btree_level_count(root->left),
	btree_level_count(root->right)));
}
