/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <andhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:23:38 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/27 19:06:57 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include "stack.h"

int		precedence(char op)
{
	if (op == '+' || op == '-')
		return (1);
	if (op == '*' || op == '/' || op == '%')
		return (2);
	return (0);
}

int		apply_op(int a, int b, char op)
{
	int res;

	res = 0;
	res = (op == '+') ? a + b : res;
	res = (op == '-') ? a - b : res;
	res = (op == '/') ? a / b : res;
	res = (op == '*') ? a * b : res;
	res = (op == '%') ? a % b : res;
	return (res);
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int		build_ans(t_stack *values, t_stack *ops)
{
	while (ops->size)
	{
		push_stack(values, apply_op(pop_stack(values),
					pop_stack(values), pop_stack(ops)));
	}
	return (values[0]);
}

int		eval_expr(char *str)
{
	t_stack	*values;
	t_stack	*ops;
	int		i;
	int		j;
	int		val;

	values = init_stack(ft_strlen(str));
	ops = init_stack(ft_strlen(str));
	while (i < ft_strlen(str))
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		else if (str[i] == '(')
		{
			push_stack(ops, str[i]);
		}
		else if (is_digit(str[i]))
		{
			val = 0;
			while (i < ft_strlen(str) && is_digit(str[i]))
			{
				val = (val * 10) + (str[i] - '0');
				i++;
			}
			push_stack(values, val);
		}
		else if (str[i] == ')')
		{
			while (ops->size && top_stack(ops) != '(')
			{
				push_stack(values, apply_op(pop_stack(values),
					pop_stack(values), pop_stack(ops)));
			}
		}
		else
		{
			while (ops->size && precedence(top_stack(ops)) >=
			precedence(str[i]))
				push_stack(values, apply_op(pop_stack(values),
					pop_stack(values), pop_stack(ops)));
		}
		i++;
	}
	return build_ans(values, ops);
}
