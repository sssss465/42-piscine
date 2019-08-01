/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:55:14 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/27 18:14:28 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	int			size;
	int			capacity;
	int			*arr;
}				t_stack;

t_stack			*init_stack(int capacity);
void			push_stack(t_stack *s, int ele);
int				pop_stack(t_stack *s);
int				top_stack(t_stack *s);

#endif
