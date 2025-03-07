/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:36:23 by taya              #+#    #+#             */
/*   Updated: 2025/03/06 22:38:15 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	stack->head = last;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
