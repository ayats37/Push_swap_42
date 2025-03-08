/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:08:04 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 16:25:07 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_input(char *input, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(input, "sa", 2) == 0 && input[2] == '\0')
		sa(stack_a);
	else if (ft_strncmp(input, "sb", 2) == 0 && input[2] == '\0')
		sb(stack_b);
	else if (ft_strncmp(input, "ss", 2) == 0 && input[2] == '\0')
		ss(stack_a, stack_b);
	else if (ft_strncmp(input, "ra", 2) == 0 && input[2] == '\0')
		ra(stack_a);
	else if (ft_strncmp(input, "rb", 2) == 0 && input[2] == '\0')
		rb(stack_b);
	else if (ft_strncmp(input, "rr", 2) == 0 && input[2] == '\0')
		rr(stack_a, stack_b);
	else if (ft_strncmp(input, "rra", 3) == 0 && input[3] == '\0')
		rra(stack_a);
	else if (ft_strncmp(input, "rrb", 3) == 0 && input[3] == '\0')
		rrb(stack_b);
	else if (ft_strncmp(input, "rrr", 3) == 0 && input[3] == '\0')
		rrr(stack_a, stack_b);
	else if (ft_strncmp(input, "pa", 2) == 0 && input[2] == '\0')
		pa(stack_a, stack_b);
	else if (ft_strncmp(input, "pb", 2) == 0 && input[2] == '\0')
		pb(stack_a, stack_b);
	else
		print_error();
}

void	read_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	char	*newline;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		newline = ft_strchr(line, '\n');
		if (newline)
			*newline = '\0';
		execute_input(line, stack_a, stack_b);
		free(line);
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	fill_stack(t_stack *stack_a, char **args, int count)
{
	int	i;

	i = count - 1;
	init_stack(stack_a);
	while (i >= 0)
		push(stack_a, (args[i--]));
}
