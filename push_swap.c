#include "push_swap.h"

void init_stack(Stack *s)
{
    s->top = -1;
}

void print_stack(Stack *s)
{
    int i;

    i = 0;
    if (s->top == -1)
    {
        printf("Stack is empty :( \n");
        return;
    }
    while (i <= s->top)
    {
        printf("%d ", s->stack[i]);
        i++;
    }
    printf("\n");
}

int pop(Stack *s)
{
    int ça_dégage;
    if (s->top >= 0)
    {
        ça_dégage = s->stack[s->top];
        s->top--;
        printf("Oust ça dégage %d\n", ça_dégage);
        return (ça_dégage);
    }
    else
    {
        printf("Oopsie doopsie cant pop\n");
        return (-1);
    }
}

int quick_sort(Stack *a, Stack *b)
{
    int pivot;
    int i;

    if (a->top <= 1)
        return 0;
    if (a->top <= 0)
        return 1;
    pivot = a->stack[0];
    i = 1;
    while (i <= a->top)
    {
        if (a->stack[i] < pivot)
            push_to_b(b, a);
        else
            rotate_a(a);
        i++;
    }
    if (a->top > 1)
        quick_sort(a, b);
    if (b->top > 0)
        quick_sort(b, a);
    return 1;
}

int main()
{
    Stack a, b;
    init_stack(&a);
    init_stack(&b);

    a.stack[++a.top] = 13;
    a.stack[++a.top] = 2;
    a.stack[++a.top] = 37;
    a.stack[++a.top] = 64;
    a.stack[++a.top] = 28;
    a.stack[++a.top] = 87;

    printf("Initial Stack a:\n");
    print_stack(&a);

    printf("Initial Stack b:\n");
    print_stack(&b);

    quick_sort(&a, &b);

    printf("Sorted Stack a:\n");
    print_stack(&a);

    printf("Sorted Stack b:\n");
    print_stack(&b);

    return 0;
}