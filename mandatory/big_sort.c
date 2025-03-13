/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:17:35 by taya              #+#    #+#             */
/*   Updated: 2025/03/13 09:47:01 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_range(t_stack *stack_a)
{
	int	max;

	max = stack_a->size;
	return (max * 0.048 + 10);
}

void	process_move_to_stack_b(t_stack *stack_a, t_stack *stack_b,
		int *range_threshold, int *min_range)
{
	// printf ("%d --- %d\n", *range_threshold , stack_a->head->index);
	if (stack_a->head->index > *range_threshold)
	{
		ra(stack_a);
	}
	else if (stack_a->head->index < *min_range)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		(*range_threshold)++;
		(*min_range)++;
		stack_a->rotation_count = 0;
	}
	else if (stack_a->head->index >= *min_range
			&& stack_a->head->index <= *range_threshold)
	{
		pb(stack_a, stack_b);
		(*range_threshold)++;
		(*min_range)++;
		stack_a->rotation_count = 0;
	}
}

void	init_range_params(t_stack *stack_a, int *range_threshold,
		int *min_range)
{
	*range_threshold = max_range(stack_a);
	*min_range = 0;
}

void	move_to_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	range_threshold;
	int	min_range;

	init_range_params(stack_a, &range_threshold, &min_range);
	while (stack_a->head)
	{
		process_move_to_stack_b(stack_a, stack_b, &range_threshold, &min_range);
		if (stack_a->size == 1 && stack_a->head->index > range_threshold)
			break ;
	}
}

void	move_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;
	int	max_pos;
	int	mid_point;

	while (stack_b->head)
	{
		max_index = find_max_index(stack_b);
		max_pos = find_index_position(stack_b, max_index);
		mid_point = stack_b->size / 2;
		if (max_pos >= mid_point)
		{
			while (stack_b->head->value != max_index)
				rrb(stack_b);
		}
		else
		{
			while (stack_b->head->value != max_index)
				rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	range_sort(t_stack *stack_a, t_stack *stack_b)
{
	move_to_stack_b(stack_a, stack_b);
	// t_stack *tmp = stack_b;
	// while (tmp->head)
	// {
	// 	printf("%d\n", tmp->head->value);
	// 	tmp->head= tmp->head->next;	
	// }
	move_to_stack_a(stack_a, stack_b);
}
