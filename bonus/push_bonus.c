/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:35:58 by taya              #+#    #+#             */
/*   Updated: 2025/03/06 22:37:39 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (stack->size == 0)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		value;

	if (stack->size == 0)
		return (-1);
	tmp = stack->head;
	value = tmp->value;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	free(tmp);
	stack->size--;
	return (value);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_b->size == 0)
		return ;
	value = pop(stack_b);
	push(stack_a, value);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_a->size == 0)
		return ;
	value = pop(stack_a);
	push(stack_b, value);
	write(1, "pb\n", 3);
}
