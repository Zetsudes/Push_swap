/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:05:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:19 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(Stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	get_min(Stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->stack[0];
	while (i <= stack->top)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	get_pos(Stack *stack, int num)
{
	int	i;

	i = 0;
	while (i <= stack->top)
	{
		if (stack->stack[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

void	move_min_to_b(Stack *a, Stack *b)
{
	int	min;
	int	pos;

	min = get_min(a);
	pos = get_pos(a, min);
	if (pos <= a->top / 2)
	{
		while (a->stack[a->top] != min)
			rotate_a(a);
	}
	else
	{
		while (a->stack[a->top] != min)
			reverse_rotate_a(a);
	}
	push_to_b(b, a);
}
