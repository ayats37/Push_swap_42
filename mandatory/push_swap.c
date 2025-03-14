/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:59:24 by taya              #+#    #+#             */
/*   Updated: 2025/03/14 23:57:19 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 5)
	{
		if (stack_a->size == 2)
			sort_two(stack_a);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else if (stack_a->size == 4)
			sort_four(stack_a, stack_b);
		else if (stack_a->size == 5)
			sort_five(stack_a, stack_b);
		return ;
	}
	range_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;
	int		count;

	if (argc <= 1)
		return (0);
	count = 0;
	args = parse_args(argc, argv, &count);
	if (!args || count == 0 || duplicate(args, count) || !validate_numbers(args,
			count))
	{
		free_split(args);
		return (write(2, "Error\n", 6), 1);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	fill_stack(&stack_a, args, count);
	fill_index(&stack_a);
	free_split(args);
	sort_stack(&stack_a, &stack_b);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
