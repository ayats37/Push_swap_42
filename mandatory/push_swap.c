/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:59:24 by taya              #+#    #+#             */
/*   Updated: 2025/03/03 04:41:20 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_digit(int c) 
{
    return (c >= '0' && c <= '9');
}
int valid_nbr(const char *str)
{
	int i;
	
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return(1);
}
int	duplicate(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}
 
void init_stack(t_stack *stack) {
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	int i;
	int num;

	if (argc < 2 || duplicate(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 1;
	while(i < argc)
	{
		if (!valid_nbr(argv[i]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	init_stack(&stack_a);
	init_stack(&stack_b);
	i = argc - 1;
	while (i > 0)
	{
		num = ft_atoi(argv[i]);
		push(&stack_a, num);
		i--;
	}
	sort_stack(&stack_a, &stack_b);
	return(0);
}
