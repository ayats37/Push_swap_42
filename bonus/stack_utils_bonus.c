/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:08:04 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 01:26:42 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_input(t_stack *stack_a, t_stack *stack_b)
{
	char *line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (ft_strncmp(line, "sa", 2) == 0)
			sa(stack_a);
		else if (ft_strncmp(line, "sb", 2) == 0)
			sb(stack_b);
		else if (ft_strncmp(line, "ss", 2) == 0)
			ss(stack_a, stack_b);
		else if (ft_strncmp(line, "ra", 2) == 0)
			ra(stack_a);
		else if (ft_strncmp(line, "rb", 2) == 0)
			rb(stack_b);
		else if (ft_strncmp(line, "rr", 2) == 0)
			rr(stack_a, stack_b);
		else if (ft_strncmp(line, "rra", 3) == 0)
			rra(stack_a);
		else if (ft_strncmp(line, "rrb", 3) == 0)
			rrb(stack_b);
		else if (ft_strncmp(line, "rrr", 3) == 0)
			rrr(stack_a, stack_b);
		else if (ft_strncmp(line, "pa", 2) == 0)
			pa(stack_a, stack_b);
		else if (ft_strncmp(line, "pb", 2) == 0)
			pb(stack_a, stack_b);
		else
		{
			write(1, "Error\n", 6);
			free(line);
			exit(1);
		}
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
int	sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}


int	is_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int	init_stacks(int argc, char **argv, t_stack *stack_a)
{
	int	value;
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		value = ft_atoi(argv[i]);
		if (is_duplicate(stack_a, value))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		push(stack_a, value);
		i--;
	}
	return (0);
}
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
