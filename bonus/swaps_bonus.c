/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:35:44 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 01:57:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (stack_a->size > 1)
	{
		first = stack_a->head;
		second = first->next;
		tmp = first->value;
		first->value = second->value;
		second->value = tmp;
	}
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (stack_b->size > 1)
	{
		first = stack_b->head;
		second = first->next;
		tmp = first->value;
		first->value = second->value;
		second->value = tmp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
