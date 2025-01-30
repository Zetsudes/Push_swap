/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamohame <zamohame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:49:40 by zamohame          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:26 by zamohame         ###   ########.fr       */
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

typedef struct
{
	int	value;
	int	index;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	int	total_cost;
}		t_move;

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
int		get_max(Stack *stack);
int		get_min(Stack *stack);
int		get_pos(Stack *stack, int num);
void	move_min_to_b(Stack *a, Stack *b);
void	sort_big(Stack *a, Stack *b);

#endif
