#include "push_swap.h"

int push_to_a(Stack *a, Stack *b)
{
    if (a->top >= MAX_SIZE - 1 || b->top < 0)
        return (0);
    a->top++;
    a->stack[a->top] = b->stack[b->top];
    b->top--;
    return (1);
}

int push_to_b(Stack *b, Stack *a)
{
    if (a->top < 0 || b->top >= MAX_SIZE - 1)
        return (0);
    b->top++;
    b->stack[b->top] = a->stack[a->top];
    a->top--;
    return (1);
}