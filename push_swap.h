/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:40 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/24 17:39:38 by zamohame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MAX_SIZE 100

typedef struct
{
	int	stack[MAX_SIZE];
	int	top;
}		Stack;

void	init_stack(Stack *s);
void	print_stack(Stack *s);
int		push(Stack *stack, int num);
int		push_to_a(Stack *a, Stack *b);
int		push_to_b(Stack *b, Stack *a);
int		swap_a(Stack *a);
int		swap_b(Stack *b);
int		swap_both(Stack *a, Stack *b);
int		rotate_a(Stack *a);
int		rotate_b(Stack *b);
int		rotate_both(Stack *a, Stack *b);
int		reverse_rotate_a(Stack *a);
int		reverse_rotate_b(Stack *b);
int		reverse_rotate_both(Stack *a, Stack *b);
void	sort_three(Stack *a);
void	sort_five(Stack *a, Stack *b);
int		handle_error(void);

int		has_duplicate(Stack *s, int num);
int		is_number(char *str);
int		is_sorted(Stack *s);
int		find_median(Stack *s);
void	sort(Stack *a, Stack *b);
void	make_next_move(Stack *a, Stack *b);
int		cost(int index, int stack_size);

#endif
