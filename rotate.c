#include "push_swap.h"

int	rotate_a(Stack *a)
{
	int	tmp;
	int	i;

	i = a->top;
	tmp = a->stack[i];
	if (a->top <= 0)
		return (0);
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = tmp;
	write(1, "ra\n", 3);
	return (1);
}

int	rotate_b(Stack *b)
{
	int	tmp;
	int	i;

	i = b->top;
	if (i <= 0)
		return (0);
	tmp = b->stack[i];
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = tmp;
	write(1, "rb\n", 3);
	return (1);
}

int	rotate_both(Stack *a, Stack *b)
{
	if (a->top <= 0 || b->top <= 0)
		return (0);
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
	return (1);
}
