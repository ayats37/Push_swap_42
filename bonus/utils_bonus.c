/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:08:26 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 15:42:46 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->size <= 1)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_duplicate(char **args, int count)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_nbr(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_numbers(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!valid_nbr(args[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**parse_args(int argc, char **argv, int *count, int *free_flag)
{
	char	**args;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*free_flag = 1;
		*count = 0;
		while (args && args[*count])
			(*count)++;
	}
	else
	{
		args = argv + 1;
		*count = argc - 1;
		*free_flag = 0;
	}
	return (args);
}

