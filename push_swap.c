#include "push_swap.h"

void	init_stack(Stack *s)
{
	s->top = -1;
}

int	handle_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	has_duplicate(Stack *s, int num)
{
	int	i;

	i = 0;
	while (i <= s->top)
	{
		if (s->stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	sort_five(Stack *a, Stack *b)
{
	int	size;
	int	median;
	int	pushed;
	int	max;
	int	max_pos;
	int	i;

	size = a->top + 1;
	pushed = 0;
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
		max = b->stack[0];
		max_pos = 0;
		i = 1;
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

int	main(int argc, char **argv)
{
	Stack	stack_a;
	Stack	stack_b;
	int		i;
	long	num;
	int		top;
	int		bis;
	int		bisbis;

	if (argc < 2)
		return (handle_error());
	init_stack(&stack_a);
	init_stack(&stack_b);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (handle_error());
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (handle_error());
		if (has_duplicate(&stack_a, (int)num))
			return (handle_error());
		push(&stack_a, (int)num);
		i++;
	}
	if (is_sorted(&stack_a))
	{
		top = stack_a.stack[stack_a.top];
		bis = stack_a.stack[stack_a.top - 1];
		bisbis = stack_a.stack[stack_a.top - 2];
		printf("Top : %d\n 2nd : %d\n 3rd : %d", top, bis, bisbis);
		return (0);
	}
	top = stack_a.stack[stack_a.top];
	bis = stack_a.stack[stack_a.top - 1];
	bisbis = stack_a.stack[stack_a.top - 2];
	if (argc == 3 && stack_a.stack[stack_a.top] > stack_a.stack[stack_a.top
		- 1])
	{
		swap_a(&stack_a);
		return (0);
	}
	print_stack(&stack_a);
	if (argc == 4)
	{
		sort_three(&stack_a);
		top = stack_a.stack[stack_a.top];
		bis = stack_a.stack[stack_a.top - 1];
		bisbis = stack_a.stack[stack_a.top - 2];
		print_stack(&stack_a);
		printf("Top : %d\n 2nd : %d\n 3rd : %d", top, bis, bisbis);
		return (0);
	}
	if (argc <= 6)
	{
		sort_five(&stack_a, &stack_b);
		print_stack(&stack_a);
		return (0);
	}
	print_stack(&stack_a);
	return (0);
}
