/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:35:44 by taya              #+#    #+#             */
/*   Updated: 2025/03/06 22:36:53 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size < 2)
		return ;
	tmp = stack_a->head->value;
	stack_a->head->value = stack_a->tail->value;
	stack_a->tail->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size < 2)
		return ;
	tmp = stack_b->head->value;
	stack_b->head->value = stack_b->tail->value;
	stack_b->tail->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp_a;
	int	tmp_b;

	if (stack_a->size < 2 || stack_b->size < 2)
		return ;
	tmp_a = stack_a->head->value;
	stack_a->head->value = stack_a->tail->value;
	stack_a->tail->value = tmp_a;
	tmp_b = stack_b->head->value;
	stack_b->head->value = stack_b->tail->value;
	stack_b->tail->value = tmp_b;
	write(1, "ss\n", 3);
}
