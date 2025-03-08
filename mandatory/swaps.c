/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:58:36 by taya              #+#    #+#             */
/*   Updated: 2025/03/08 02:04:44 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
