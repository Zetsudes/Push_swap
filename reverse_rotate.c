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

    if (a->top <= 0)
        return (0);
    tmp = a->stack[a->top];
    i = a->top;
    while (i--) 
        a->stack[i + 1] = a->stack[i];
    a->stack[0] = tmp;
    ft_printf("rra\n");
    return (1);
}

int reverse_rotate_b(Stack *b)
{
    int tmp;
    int i;

    if (b->top <= 0)
        return (0);
    tmp = b->stack[b->top];
    i = b->top;
    while (i--)
        b->stack[i + 1] = b->stack[i];
    b->stack[0] = tmp;
    ft_printf("rrb\n");
    return (1);
}

int reverse_rotate_both(Stack *a, Stack *b)
{
    int tmp_a;
    int tmp_b; 
    int i;

    if (a->top <= 0 || b->top <= 0)
        return (0);
    tmp_a = a->stack[a->top];
    i = a->top;
    while (i--)
        a->stack[i + 1] = a->stack[i];
    a->stack[0] = tmp_a;
    tmp_b = b->stack[b->top];
    i = b->top;
    while (i--)
        b->stack[i + 1] = b->stack[i];
    b->stack[0] = tmp_b;
    ft_printf("rrr\n");
    return (1);
}
