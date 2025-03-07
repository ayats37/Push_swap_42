/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:17:35 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 22:50:32 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	range_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	range_threshold;
// 	int	min_range;
// 	int	current_value;
// 	int	max_value;
// 	int	max_pos;
// 	int	mid_point;

// 	range_threshold = calculate_range_threshold(stack_a);
// 	min_range = 0;
// 	while (stack_a->head)
// 	{
// 		current_value = stack_a->head->value;
// 		if (current_value > range_threshold)
// 		{
// 			if (stack_a->size == 1)
// 				break ;
// 			ra(stack_a);
// 		}
// 		else if (current_value < min_range)
// 		{
// 			pb(stack_a, stack_b);
// 			rb(stack_b);
// 			range_threshold++;
// 			min_range++;
// 		}
// 		else if (current_value >= min_range && current_value <= range_threshold)
// 		{
// 			pb(stack_a, stack_b);
// 			range_threshold++;
// 			min_range++;
// 		}
// 	}
// 	while (stack_b->head)
// 	{
// 		max_value = find_max_value(stack_b);
// 		max_pos = find_value_position(stack_b, max_value);
// 		mid_point = stack_b->size / 2;
// 		if (max_pos >= mid_point)
// 		{
// 			while (stack_b->head->value != max_value)
// 				rrb(stack_b);
// 		}
// 		else
// 		{
// 			while (stack_b->head->value != max_value)
// 				rb(stack_b);
// 		}
// 		pa(stack_a, stack_b);
// 	}
// }

void	init_range_params(t_stack *stack_a, int *range_threshold,
		int *min_range)
{
	*range_threshold = calculate_range_threshold(stack_a);
	*min_range = 0;
}

void	process_move_to_stack_b(t_stack *stack_a, t_stack *stack_b,
		int *range_threshold, int *min_range)
{
	int	current_value;

	current_value = stack_a->head->value;
	if (current_value > *range_threshold)
	{
		if (stack_a->size == 1)
			return ;
		ra(stack_a);
	}
	else if (current_value < *min_range)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		(*range_threshold)++;
		(*min_range)++;
	}
	else if (current_value >= *min_range && current_value <= *range_threshold)
	{
		pb(stack_a, stack_b);
		(*range_threshold)++;
		(*min_range)++;
	}
}

void	move_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	range_threshold;
	int	min_range;

	init_range_params(stack_a, &range_threshold, &min_range);
	while (stack_a->head)
	{
		process_move_to_stack_b(stack_a, stack_b, &range_threshold, &min_range);
		if (stack_a->size == 1 && stack_a->head->value > range_threshold)
			break ;
	}
}

void	move_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_value;
	int	max_pos;
	int	mid_point;

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

void	range_sort(t_stack *stack_a, t_stack *stack_b)
{
	move_to_stack_b(stack_a, stack_b);
	move_to_stack_a(stack_a, stack_b);
}
