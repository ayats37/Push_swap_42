/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:43:46 by taya              #+#    #+#             */
/*   Updated: 2025/03/13 09:45:47 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_range_threshold(t_stack *stack)
{
	return ((int)(stack->size * 0.048 + 10));
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	max_index = current->value;
	while (current)
	{
		if (current->value > max_index)
			max_index = current->value;
		current = current->next;
	}
	return (max_index);
}

int	find_index_position(t_stack *stack, int target_index)
{
	t_node	*current;
	int		position;

	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->value == target_index)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}
void fill_index(t_stack *stack_a)
{
	int i;
	t_node *n1;
	t_node *n2;

	i = 0;
	while (i <= stack_a->size)
	{
		n1 = NULL;
		n2 = stack_a->head;
		while (n2 != NULL)
        {
            if (n2->index == -1 && (n1 == NULL || n2->value < n1->value))
                n1 = n2;
            n2 = n2->next;
        }
        if (n1 != NULL)
            n1->index = i;
        i++;
				
	}
}

