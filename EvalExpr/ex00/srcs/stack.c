/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:00:09 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/27 18:14:52 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*init_stack(int capacity)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	s->arr = malloc(sizeof(int) * capacity);
	s->capacity = capacity;
	return (s);
}

void	push_stack(t_stack *s, int ele)
{
	if (s->size < s->capacity)
	{
		s->arr[s->size] = ele;
		s->size++;
	}
}

int		pop_stack(t_stack *s)
{
	int res;

	if (s->size > 0)
	{
		res = s->arr[(s->size) - 1];
		(s->size)--;
	}
	return (res);
}

int		top_stack(t_stack *s)
{
	int res;

	if (s->size > 0)
	{
		res = s->arr[(s->size) - 1];
	}
	return (res);
}
