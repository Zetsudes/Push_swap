/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:49:32 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:49:51 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	push(Stack *stack, int num)
{
	if (stack->top >= MAX_SIZE - 1)
		return (0);

	stack->top++;
	stack->stack[stack->top] = num;

	return (1);
}

int	push_to_a(Stack *a, Stack *b)
{
	int i;

	if (a->top >= MAX_SIZE - 1 || b->top < 0)
		return (0);
	i = a->top + 1;
	while (i--)
		a->stack[i + 1] = a->stack[i];
	a->stack[0] = b->stack[0];
	i = 0;
	while (i < b->top)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	a->top++;
	b->top--;
	ft_printf("pa\n");
	return (1);
}

int	push_to_b(Stack *b, Stack *a)
{
	int i;

	if (b->top >= MAX_SIZE - 1 || a->top < 0)
		return (0);
	i = b->top + 1;
	while (i--)
		b->stack[i + 1] = b->stack[i];
	b->stack[0] = a->stack[0];
	i = 0;
	while (i < a->top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	b->top++;
	a->top--;
	ft_printf("pb\n");
	return (1);
}

void	push_a_bit(Stack *a, Stack *b)
{
	int total;
	int bit_size;
	int pushed;

	total = a->top + 1;
	bit_size = total / 15;
	pushed = 0;
	while (a->top >= 0)
	{
		if (get_rank(a, a->stack[0]) <= pushed + bit_size)
		{
			push_to_b(b, a);
			pushed++;
			if (b->top >= 0 && b->stack[0] < pushed - (bit_size / 2))
				rotate_b(b);
		}
		else
			rotate_a(a);
	}
}

void	push_back(Stack *a, Stack *b)
{
	int max;
	int max_pos;

	while (b->top >= 0)
	{
		max = get_max(b);
		max_pos = get_pos(b, max);
		if (max_pos <= (b->top / 2))
		{
			while (b->stack[0] != max)
				rotate_b(b);
		}
		else
		{
			while (b->stack[0] != max)
				reverse_rotate_b(b);
		}
		push_to_a(a, b);
	}
}
