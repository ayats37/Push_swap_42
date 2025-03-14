/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:01:53 by taya              #+#    #+#             */
/*   Updated: 2025/03/14 23:56:57 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**parse_args(int argc, char **argv, int *count)
{
	char	**args;
	char	*ar;

	ar = join_args(argc, argv);
	args = ft_split(ar, ' ');
	free(ar);
	*count = 0;
	while (args && args[*count])
		(*count)++;
	return (args);
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
	if (!args || count == 0 || is_duplicate(args, count)
		|| !validate_numbers(args, count))
	{
		free_split(args);
		return (write(2, "Error\n", 6), 1);
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	fill_stack(&stack_a, args, count);
	free_split(args);
	read_input(&stack_a, &stack_b);
	if (sorted(&stack_a) && (stack_b.size == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
