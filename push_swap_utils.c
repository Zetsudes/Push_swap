/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:57 by zamohame          #+#    #+#             */
/*   Updated: 2025/02/10 11:52:02 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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