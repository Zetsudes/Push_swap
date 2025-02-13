/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:32 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:49:51 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int push(Stack *stack, int num)
{
    if (stack->top >= MAX_SIZE - 1)
        return (0);

    stack->top++;  
    stack->stack[stack->top] = num; 

    return (1);
}

int push_to_a(Stack *a, Stack *b)
{
    int i;

    if (a->top >= MAX_SIZE - 1 || b->top < 0)
        return (0);
    i = a->top + 1;
    while (i--)
        a->stack[i + 1] = a->stack[i];
    a->stack[0] = b->stack[0];
    i = 0;
    while (i < b->top)
    {
        b->stack[i] = b->stack[i];
        i++;
    }
    a->top++;
    b->top--;
    ft_printf("pa\n");
    return (1);
}

int push_to_b(Stack *b, Stack *a)
{
    int i;

    if (b->top >= MAX_SIZE - 1 || a->top < 0)
        return (0);
    i = b->top + 1;
    while (i--)
        b->stack[i + 1] = b->stack[i];
    b->stack[0] = a->stack[0];
    i = 0;
    while (i < a->top)
    {
        a->stack[i] = a->stack[i + 1];
        i++;
    }
    b->top++;
    a->top--;
    ft_printf("pb\n");
    return (1);
}