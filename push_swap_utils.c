/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:57 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/14 09:53:45 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	print_stack(Stack *s)
{
	int	i;

	i = 0;
	if (s->top == -1)
		return ;
	printf("\n");
	printf("Stack : ");
	while (i <= s->top)
	{
		printf("%d ", s->stack[i]);
		i++;
	}
	printf("\n");
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

int	is_sorted(Stack *s)
{
	int	i;

	i = 0;
	while (i < s->top)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (0);
		i++;
	}
	if (s->stack[s->top] > s->stack[0])
		return (0);
	return (1);
}

int	is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	find_median(Stack *s)
{
	int	tmp[s->top + 1];
	int	i;
	int	j;
	int	temp;

	i = 0;
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
	return (tmp[(s->top) / 2]);
}
