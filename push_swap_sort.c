/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/14 09:51:42 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 10:17:47 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort(Stack *a, Stack *b)
{
	int size;

	size = a->top + 1;
	if (is_sorted(a))
		return ;
	if (size == 2)
	{
		swap_a(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	if (size == 4)
	{
		sort_four(a, b);
		return ;
	}
	if (size == 5)
	{
		sort_five(a, b);
		return ;
	}
	sort_big(a, b);
}

void	sort_three(Stack *a)
{
	int first;
	int second;
	int third;

	first = a->stack[0];
	second = a->stack[1];
	third = a->stack[2];
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

void	sort_four(Stack *a, Stack *b)
{
	if (is_sorted(a))
		return ;

	move_min_to_b(a, b);

	sort_three(a);

	push_to_a(a, b);
}

void	sort_five(Stack *a, Stack *b)
{
	move_min_to_b(a, b);
	move_min_to_b(a, b);

	sort_three(a);

	push_to_a(a, b);
	push_to_a(a, b);
}

void	push_sorted_chunks(Stack *a, Stack *b, int chunk_size)
{
	int total = a->top + 1;
	int pushed = 0;

	while (pushed < total)
	{
		int limit = pushed + chunk_size;
		if (limit > total)
			limit = total; // Adjust for the last chunk

		while (a->top >= 0 && get_rank(a, a->stack[0]) <= limit)
		{
			push_to_b(b, a);
			pushed++;

			// Rotate `b` only if necessary to keep some order
			if (b->top > 0 && b->stack[0] < pushed - (chunk_size / 2))
			{
				rotate_b(b);
			}
		}
	}
}

void	smart_push_back(Stack *a, Stack *b)
{
	while (b->top >= 0)
	{
		int max = get_max(b);
		int max_pos = get_pos(b, max);

		// Optimize how we retrieve the max value
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

void	sort_big(Stack *a, Stack *b)
{
	int total = a->top + 1;

	if (total > 100)
	{
		int chunk_size = 100; // Always push chunks of 100
		push_sorted_chunks(a, b, chunk_size);

		// Sort each batch inside `b`
		push_a_bit(a, b);
		push_back(a, b);

		// Push remaining numbers from `b` in sorted order
		smart_push_back(a, b);
	}
	else
	{
		push_a_bit(a, b);
		push_back(a, b);
	}
}
