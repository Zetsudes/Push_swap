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
    write(1, "rra\n", 3);
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
    write(1, "rrb\n", 3);
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