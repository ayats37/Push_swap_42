/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:01:53 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 00:53:56 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	if (argc < 2)
		return (0);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_a.size = 0;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	stack_b.size = 0;
	if (init_stacks(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	read_input(&stack_a, &stack_b);
	if (sorted(&stack_a) && (stack_b.size == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}