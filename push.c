/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:32 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/24 17:30:31 by zamohame         ###   ########.fr       */
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
	if (a->top >= MAX_SIZE - 1 || b->top < 0)
		return (0);
	a->stack[++a->top] = b->stack[b->top--];
	write(1, "pa\n", 3);
	return (1);
}

int	push_to_b(Stack *b, Stack *a)
{
	if (a->top < 0 || b->top >= MAX_SIZE - 1)
		return (0);
	b->stack[++b->top] = a->stack[a->top--];
	write(1, "pb\n", 3);
	return (1);
}
