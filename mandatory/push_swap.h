/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:59:45 by taya              #+#    #+#             */
/*   Updated: 2025/03/04 23:29:00 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
}					t_stack;

t_node				*create_node(int value);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
int					get_index_value(t_stack *stack, int index);
void				sort_two(t_stack *stack_a);
void				sort_three(t_stack *stack_a);
int					get_min_index(t_stack *stack);
void				get_rotate_type(t_stack *stack, int index, int *direction,
						int *rotations);
void				sort_four(t_stack *stack_a, t_stack *stack_b);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
void				free_stack(t_stack *stack);
void				free_split(char **split);
char				**parse_args(int argc, char **argv, int *count,
						int *free_flag);
void				fill_stack(t_stack *stack_a, char **args, int count);
int					is_sorted(t_stack *stack);
int					is_digit(int c);
int					valid_nbr(const char *str);
int					duplicate(char **args, int count);
void				init_stack(t_stack *stack);
void				init_stack(t_stack *stack);
int					validate_numbers(char **args, int count);
int					calculate_range_threshold(t_stack *stack);
int					find_value_position(t_stack *stack, int target_value);
void				advanced_sorting_strategy(t_stack *stack_a,
						t_stack *stack_b);

#endif