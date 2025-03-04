/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:38:11 by taya              #+#    #+#             */
/*   Updated: 2025/03/04 01:19:11 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->size != 2)
		return ;
	if (stack_a->head->value > stack_a->head->next->value)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a->size != 3)
		return ;
	a = get_index_value(stack_a, 0);
	b = get_index_value(stack_a, 1);
	c = get_index_value(stack_a, 2);
	if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	direction;
	int	rotations;
	int	i;

	i = 0;
	if (stack_a->size != 4)
		return ;
	min_index = get_min_index(stack_a);
	get_rotate_type(stack_a, min_index, &direction, &rotations);
	while (i < rotations)
	{
		if (direction == 1)
			ra(stack_a);
		else
			rra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	direction;
	int	rotations;
	int	i;

	i = 0;
	if (stack_a->size != 5)
		return ;
	min_index = get_min_index(stack_a);
	get_rotate_type(stack_a, min_index, &direction, &rotations);
	while (i < rotations)
	{
		if (direction == 1)
			ra(stack_a);
		else
			rra(stack_a);
		i++;
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
