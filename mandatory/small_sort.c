/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:38:11 by taya              #+#    #+#             */
/*   Updated: 2025/03/03 00:10:35 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_two(t_stack *stack_a)
{
	if (stack_a->size != 2)
		return;
	if (stack_a->head->value > stack_a->head->next->value)
		sa(stack_a);
}

void sort_three(t_stack *stack_a)
{
	if (stack_a->size != 3)
		return;
	int a;
	int b;
	int c;

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
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
}
void sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size != 4)
		return;
	
}

