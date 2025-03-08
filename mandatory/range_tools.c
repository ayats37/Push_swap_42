/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:46 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 01:01:47 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_range_threshold(t_stack *stack)
{
	return ((int)(stack->size * 0.048 + 10));
}

int	find_max_value(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	max_value = current->value;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	find_value_position(t_stack *stack, int target_value)
{
	t_node	*current;
	int		position;

	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->value == target_value)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

void	handle_rotation_and_threshold(t_stack *stack_a, int *range_threshold)
{
	if (stack_a->size == 1)
		return ;
	ra(stack_a);
	stack_a->rotation_count++;
	if (stack_a->rotation_count >= stack_a->size)
	{
		stack_a->rotation_count = 0;
		(*range_threshold)++;
	}
}
