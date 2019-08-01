/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:45:40 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/26 16:47:18 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

void	ft_app_level(t_btree *root,
void (*applyf)(void *item, int current_level, int is_first_elem),
int curr, int mx, int *flag)
{
	if (root == 0)
		return ;
	if (curr == mx)
	{
		(*applyf)(root->item, curr, *flag);
		*flag = 0;
	}
	else 
	{
		ft_app_level(root->left, applyf, curr+1, mx, flag);
		ft_app_level(root->right, applyf, curr+1, mx, flag);	
	}
}

void	btree_apply_by_level(t_btree *root, 
void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		height;
	int		i;
	int		*flag;

	i = 1;
	height = btree_level_count(root);
	flag = malloc(sizeof(int));
	while (i <= height)
	{
		*flag = 1;
		ft_app_level(root, applyf, 1, i, flag);
		i++;
	}
	free(flag);
}
