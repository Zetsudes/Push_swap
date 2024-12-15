#include "push_swap.h"

int swap_a(Stack *a)
{
    int tmp;

    if (a->top > 0)
    {
        tmp = a->stack[a->top];
        a->stack[a->top] = a->stack[a->top - 1];
        a->stack[a->top - 1] = tmp;
        return (1);
    }
    else
        return (0);
}

int swap_b(Stack *b)
{
    int tmp;

    if (b->top > 0)
    {
        tmp = b->stack[b->top];
        b->stack[b->top] = b->stack[b->top - 1];
        b->stack[b->top - 1] = tmp;
        return (1);
    }
    else
        return (0);
}

int swap_both(Stack *a, Stack *b)
{

    if (!(a->top > 0 && b->top > 0))
        return (0);
    swap_a(a);
    swap_b(b);
    return (1);
}