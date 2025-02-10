/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:22 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:23:30 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int reverse_rotate_a(Stack *a)
{
    int tmp;
    int i;

    i = 0;
    if (a->top <= 0)
        return (0);
    tmp = a->stack[0];
    while (i <= a->top)
    {
        a->stack[i] = a->stack[i + 1];
        i++;
    }
    a->stack[a->top] = tmp;
    ft_printf("rra\n");
    return (1);
}

int reverse_rotate_b(Stack *b)
{
    int tmp;
    int i;

    i = 0;
    if (b->top <= 0)
        return (0);
    tmp = b->stack[0];
    while (i <= b->top)
    {
        b->stack[i] = b->stack[i + 1];
        i++;
    }
    b->stack[b->top] = tmp;
    ft_printf("rrb\n");
    return (1);
}

int reverse_rotate_both(Stack *a, Stack *b)
{
    if (a->top <= 0 || b->top <= 0)
        return (0);
    reverse_rotate_a(a);
    reverse_rotate_b(b);
    write(1, "rrr\n", 3);
    return (1);
}
