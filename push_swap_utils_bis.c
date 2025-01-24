/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:05:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/24 17:38:50 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(int index, int stack_size)
{
	int	rotate_cost;
	int	reverse_rotate_cost;

	rotate_cost = index;
	reverse_rotate_cost = stack_size - index;
	if (rotate_cost <= reverse_rotate_cost)
		return (rotate_cost);
	return (reverse_rotate_cost);
}

void	make_next_move(Stack *a, Stack *b)
{
	int	i;
	int	best_index;

	i = 0;
	best_index = -1;
	while (++i <= a->top)
	{
		if (cost(i, a->top + 1) < cost(best_index, a->top + 1))
			best_index = i;
	}
	while (best_index > 0)
	{
		rotate_a(a);
		best_index--;
	}
	while (best_index < a->top)
	{
		reverse_rotate_a(a);
		best_index++;
	}
	push_to_b(b, a);
}
