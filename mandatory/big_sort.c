/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:17:35 by taya              #+#    #+#             */
/*   Updated: 2025/03/06 20:49:01 by taya             ###   ########.fr       */
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

void	range_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	range_threshold;
	int	min_range;
	int	current_value;
	int	max_value;
	int	max_pos;
	int	mid_point;

	range_threshold = calculate_range_threshold(stack_a);
	min_range = 0;
	while (stack_a->head)
	{
		current_value = stack_a->head->value;
		if (current_value > range_threshold)
		{
			if (stack_a->size == 1)
      	break;
			ra(stack_a);	
		}
		else if (current_value < min_range)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			range_threshold++;
			min_range++;
		}
		else if (current_value >= min_range && current_value <= range_threshold)
		{
			pb(stack_a, stack_b);
			range_threshold++;
			min_range++;
		}
	}
	while (stack_b->head)
	{
		max_value = find_max_value(stack_b);
		max_pos = find_value_position(stack_b, max_value);
		mid_point = stack_b->size / 2;
		if (max_pos >= mid_point)
		{
			while (stack_b->head->value != max_value)
				rrb(stack_b);
		}
		else
		{
			while (stack_b->head->value != max_value)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
