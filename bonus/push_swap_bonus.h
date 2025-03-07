/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:02:33 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 15:59:23 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
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

void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
int					sorted(t_stack *stack);
void				free_stack(t_stack *stack);
int					is_duplicate(char **args, int count);
t_node				*create_node(int value);
void				free_split(char **split);
void				execute_input(char *input, t_stack *stack_a,
						t_stack *stack_b);
void				read_input(t_stack *stack_a, t_stack *stack_b);
char				**parse_args(int argc, char **argv, int *count,
						int *free_flag);
void				init_stack(t_stack *stack);
int					validate_numbers(char **args, int count);
int					valid_nbr(const char *str);
int					is_digit(int c);
void				fill_stack(t_stack *stack_a, char **args, int count);
void				print_error(void);

#endif