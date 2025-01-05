#include "push_swap.h"

void init_stack(Stack *s)
{
    s->top = -1;
}

int handle_error()
{
    write(2, "Error\n", 6);
    return (1);
}

int has_duplicate(Stack *s, int num)
{
    int i = 0;

    while (i <= s->top)
    {
        if (s->stack[i] == num)
            return 1;
        i++;
    }
    return 0;
}

void sort_stack(Stack *a, Stack *b)
{
    int size = a->top + 1;
    int median;
    int pushed = 0;

    median = find_median(a);
    while (a->top + 1 > 3 && pushed < (size / 2))
    {
        if (a->stack[a->top] < median)
        {
            push_to_b(b, a);
            pushed++;
        }
        else
            rotate_a(a);
    }
    sort_three(a);
    while (b->top >= 0)
    {
        int max = b->stack[0];
        int max_pos = 0;
        int i = 1;
        while (i <= b->top)
        {
            if (b->stack[i] > max)
            {
                max = b->stack[i];
                max_pos = i;
            }
            i++;
        }
        while (max_pos > 0)
        {
            rotate_b(b);
            max_pos--;
        }
        push_to_a(a, b);
    }
}

int main(int argc, char **argv)
{
    Stack stack_a;
    Stack stack_b;
    int i;
    long num;
    printf("hello");
    fflush(stdout);
    if (argc < 2)
        return handle_error();
    printf("Before init_stack\n");
    init_stack(&stack_a);
    init_stack(&stack_b);
    printf("After init_stack\n");

    i = 1;
    while (i < argc)
    {
        if (!is_number(argv[i]))
            return handle_error();
        num = atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            return handle_error();
        if (has_duplicate(&stack_a, (int)num))
            return handle_error();
        push(&stack_a, (int)num);
        print_stack(&stack_a);
        i++;
    }
    if (is_sorted(&stack_a))
        return 0;
    if (argc == 3 && stack_a.stack[stack_a.top] > stack_a.stack[stack_a.top - 1])
    {
        swap_a(&stack_a);
        return 0;
    }
    if (argc == 4)
    {
        sort_three(&stack_a);
        return 0;
    }
    sort_stack(&stack_a, &stack_b);
    print_stack(&stack_a);
    return 0;
}