#include "push_swap.h"

void print_stack(Stack *s)
{
    int i;

    i = 0;
    if (s->top == -1)
        return;
    while (i <= s->top)
    {
        printf("%d ", s->stack[i]);
        i++;
    }
    printf("\n");
}

int is_sorted(Stack *s)
{
    int i = 0;
    while (i < s->top)
    {
        if (s->stack[i] > s->stack[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int is_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (*str == '\0')
        return 0;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int find_median(Stack *s)
{
    int tmp[s->top + 1];
    int i = 0;
    int j;
    int temp;

    while (i <= s->top)
    {
        tmp[i] = s->stack[i];
        i++;
    }
    i = 0;
    while (i < s->top)
    {
        j = 0;
        while (j < s->top - i)
        {
            if (tmp[j] > tmp[j + 1])
            {
                temp = tmp[j];
                tmp[j] = tmp[j + 1];
                tmp[j + 1] = temp;
            }
            j++;
        }
        i++;
    }

    return tmp[(s->top) / 2];
}

void sort_three(Stack *a)
{
    int first = a->stack[a->top];
    int second = a->stack[a->top - 1];
    int third = a->stack[a->top - 2];

    if (first > second && second < third && first < third)
        swap_a(a);
    else if (first > second && second > third)
    {
        swap_a(a);
        reverse_rotate_a(a);
    }
    else if (first > second && second < third && first > third)
        rotate_a(a);
    else if (first < second && second > third && first < third)
    {
        swap_a(a);
        rotate_a(a);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate_a(a);
}