/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:37:39 by taya              #+#    #+#             */
/*   Updated: 2025/03/06 16:13:34 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_value(t_stack *stack, int index)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head;
	if (index < 0 || index >= stack->size)
		return (-1);
	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return (-1);
	return (current->value);
}

int	get_min_index(t_stack *stack)
{
	int		min_index;
	int		min_value;
	int		index;
	t_node	*current;

	current = stack->head;
	min_index = 0;
	index = 0;
	min_value = current->value;
	if (stack->size == 0)
		return (-1);
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	get_rotate_type(t_stack *stack, int index, int *direction,
		int *rotations)
{
	if (index < 0 || index >= stack->size)
	{
		*direction = 0;
		*rotations = 0;
		return ;
	}
	if (index <= stack->size / 2)
	{
		*direction = 1;
		*rotations = index;
	}
	else
	{
		*direction = -1;
		*rotations = stack->size - index;
	}
}

void	fill_stack(t_stack *stack_a, char **args, int count)
{
	int	i;

	i = count - 1;
	init_stack(stack_a);
	while (i >= 0)
		push(stack_a, ft_atoi(args[i--]));
}
