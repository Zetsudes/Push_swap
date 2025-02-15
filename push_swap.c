/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:49 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:36 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(Stack *s)
{
	s->top = -1;
}

void free_split_args(char **args)
{
    int i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int validate_and_push(Stack *a, char *arg)
{
    long num;

    if (!is_number(arg))
        return (0);
    num = (long)ft_atoi(arg);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    if (has_duplicate(a, (int)num))
        return (0);
    push(a, (int)num);
    return (1);
}

int	main(int argc, char **argv)
{
	Stack	a;
	Stack	b;
	int		i;
	char	**split_args;

	if (argc < 2)
		return (handle_error());
	init_stack(&a);
	init_stack(&b);
	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (handle_error());
		i = 0;
		while (split_args[i])
		{
			if (!validate_and_push(&a, split_args[i]))
            {
                free_split_args(split_args);
                return (handle_error());
            }
            i++;
		}
		free_split_args(split_args);             
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!validate_and_push(&a, argv[i]))
                return (handle_error());
            i++;
		}
	}
	if (is_sorted(&a))
		return (0);
	sort(&a, &b);
	return (0);
}
