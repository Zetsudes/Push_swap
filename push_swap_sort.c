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

void	sort_big(Stack *a, Stack *b)
{
		push_a_bit(a, b);
		push_back(a, b);
}
