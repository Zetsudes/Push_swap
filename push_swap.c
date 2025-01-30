/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/30 09:34:06 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greg_lib/libft.h"
#include "push_swap.h"

void	init_stack(Stack *s)
{
	s->top = -1;
}

int	main(int argc, char **argv)
{
	Stack	a;
	Stack	b;
	int		i;
	long	num;

	if (argc < 2)
		return (handle_error());
	init_stack(&a);
	init_stack(&b);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (handle_error());
		num = (long)ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (handle_error());
		if (has_duplicate(&a, (int)num))
			return (handle_error());
		push(&a, (int)num);
		i++;
	}
	if (is_sorted(&a))
		return (0);
	if (argc == 3 && a.stack[a.top] > a.stack[a.top - 1])
	{
		swap_a(&a);
		return (0);
	}
	print_stack(&a);
	if (argc == 4)
	{
		sort_three(&a);
		print_stack(&a);
		return (0);
	}
	if (argc <= 6)
	{
		sort_five(&a, &b);
		print_stack(&a);
		return (0);
	}
	sort(&a, &b);
	print_stack(&a);
	return (0);
}
