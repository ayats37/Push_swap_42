/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:46 by taya              #+#    #+#             */
/*   Updated: 2025/03/13 08:49:30 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_range_threshold(t_stack *stack)
{
	return ((int)(stack->size * 0.048 + 10));
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	find_index_position(t_stack *stack, int target_index)
{
	t_node	*current;
	int		position;

	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->index == target_index)
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
