/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:03 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:24:26 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int swap_a(Stack *a)
{
    int tmp;

    if (a->top > 0)
    {
        tmp = a->stack[0];
        a->stack[0] = a->stack[1];
        a->stack[1] = tmp;
        ft_printf("sa\n");
        return (1);
    }
    return (0);
}

int	swap_b(Stack *b)
{
	int	tmp;

	if (b->top > 0)
	{
		tmp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = tmp;
		ft_printf("sb\n");
		return (1);
	}
	else
		return (0);
}

int swap_both(Stack *a, Stack *b)
{
    int tmp_a;
    int tmp_b;

    if (!(a->top > 0 && b->top > 0))
        return (0);
    tmp_a = a->stack[0];
    a->stack[0] = a->stack[1];
    a->stack[1] = tmp_a;
    tmp_b = b->stack[0];
    b->stack[0] = b->stack[1];
    b->stack[1] = tmp_b; 
    ft_printf("ss\n");
    return (1);
}
