/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:51:42 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/24 17:37:20 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(Stack *a, Stack *b)
{
	while (a->top > 2)
		make_next_move(a, b);
	sort_three(a);
	while (b->top >= 0)
		push_to_a(a, b);
}

void	sort_three(Stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->stack[a->top];
	second = a->stack[a->top - 1];
	third = a->stack[a->top - 2];
	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

void	sort_five(Stack *a, Stack *b)
{
	int	size;
	int	median;
	int	pushed;
	int	max;
	int	max_pos;
	int	i;

	size = a->top + 1;
	pushed = 0;
	median = find_median(a);
	while (a->top + 1 > 3 && pushed < (size / 2))
	{
		if (a->stack[a->top] < median)
		{
			push_to_b(b, a);
			pushed++;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	while (b->top >= 0)
	{
		max = b->stack[0];
		max_pos = 0;
		i = 1;
		while (i <= b->top)
		{
			if (b->stack[i] > max)
			{
				max = b->stack[i];
				max_pos = i;
			}
			i++;
		}
		while (max_pos > 0)
		{
			rotate_b(b);
			max_pos--;
		}
		push_to_a(a, b);
	}
}
