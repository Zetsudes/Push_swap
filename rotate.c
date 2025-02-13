/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:14 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:24:00 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int rotate_a(Stack *a)
{
    int tmp;
    int i;

    if (a->top <= 0)
        return (0);
    tmp = a->stack[0];
    i = -1;
    while (++i < a->top)
        a->stack[i] = a->stack[i + 1];
    a->stack[a->top] = tmp;
    ft_printf("ra\n");
    return (1);
}

int rotate_b(Stack *b)
{
    int tmp;
    int i;

    if (b->top <= 0)
        return (0);
    tmp = b->stack[0];
    i = -1;
    while (++i < b->top)
        b->stack[i] = b->stack[i + 1];
    b->stack[b->top] = tmp;
    ft_printf("rb\n");
    return (1);
}

int rotate_both(Stack *a, Stack *b)
{
    int tmp_a, tmp_b, i;

    if (a->top <= 0 || b->top <= 0)
        return (0);
    tmp_a = a->stack[0];
    i = -1;
    while (++i < a->top)
        a->stack[i] = a->stack[i + 1];
    a->stack[a->top] = tmp_a;
    tmp_b = b->stack[0];
    i = -1;
    while (++i < b->top)
        b->stack[i] = b->stack[i + 1];
    b->stack[b->top] = tmp_b;
    ft_printf("rr\n");
    return (1);
}