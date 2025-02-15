# include "push_swap.h"

int get_min_index(Stack *a)
{
    int i;
    int min_index;

    min_index = 0;
    i = 1;
    while (i <= a->top)
    {
        if (a->stack[i] < a->stack[min_index])
            min_index = i;
        i++;
    }
    return (min_index);
}
