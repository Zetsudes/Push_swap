/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:51:42 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 10:17:47 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(Stack *a, Stack *b)
{
	int	size;

	size = a->top + 1;
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
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
void sort_five(Stack *a, Stack *b)
{
    int min;
	
    while (a->top + 1 > 3)
    {
        min = get_min(a);
        if (a->stack[a->top] == min)
            push_to_b(b, a);
        else
            rotate_a(a);
    }
    sort_three(a);
    while (b->top >= 0)
    {
        push_to_a(a, b);
        if (a->stack[a->top] > a->stack[a->top - 1])
            rotate_a(a);
    }
    while (a->stack[a->top] != get_min(a))
        rotate_a(a);
}



void	sort_big(Stack *a, Stack *b)
{
	int	size;
	int	pushed;

	size = a->top + 1;
	pushed = 0;
	while (size - pushed > 3)
	{
		move_min_to_b(a, b);
		pushed++;
	}
	sort_three(a);
	while (b->top >= 0)
		push_to_a(a, b);
}
