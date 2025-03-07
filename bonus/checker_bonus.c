/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:01:53 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 22:06:11 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;
	int		count;
	int		free_flag;

	count = 0;
	free_flag = 0;
	args = parse_args(argc, argv, &count, &free_flag);
	if (!args || count == 0 || is_duplicate(args, count)
		|| !validate_numbers(args, count))
	{
		if (free_flag)
			free_split(args);
		return (write(2, "Error\n", 6), 1);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	fill_stack(&stack_a, args, count);
	read_input(&stack_a, &stack_b);
	if (sorted(&stack_a) && (stack_b.size == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
