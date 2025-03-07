/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:08:04 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 14:53:45 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void execute_input(char *command, t_stack *stack_a, t_stack *stack_b)
{
    char *newline = ft_strchr(command, '\n');
    if (newline)
        *newline = '\0';
        
    if (ft_strncmp(command, "sa", 2) == 0 && command[2] == '\0')
        sa(stack_a);
    else if (ft_strncmp(command, "sb", 2) == 0 && command[2] == '\0')
        sb(stack_b);
    else if (ft_strncmp(command, "ss", 2) == 0 && command[2] == '\0')
        ss(stack_a, stack_b);
    else if (ft_strncmp(command, "ra", 2) == 0 && command[2] == '\0')
        ra(stack_a);
    else if (ft_strncmp(command, "rb", 2) == 0 && command[2] == '\0')
        rb(stack_b);
    else if (ft_strncmp(command, "rr", 2) == 0 && command[2] == '\0')
        rr(stack_a, stack_b);
    else if (ft_strncmp(command, "rra", 3) == 0 && command[3] == '\0')
        rra(stack_a);
    else if (ft_strncmp(command, "rrb", 3) == 0 && command[3] == '\0')
        rrb(stack_b);
    else if (ft_strncmp(command, "rrr", 3) == 0 && command[3] == '\0')
        rrr(stack_a, stack_b);
    else if (ft_strncmp(command, "pa", 2) == 0 && command[2] == '\0')
        pa(stack_a, stack_b);
    else if (ft_strncmp(command, "pb", 2) == 0 && command[2] == '\0')
        pb(stack_a, stack_b);
    else
    {
        write(1, "Error\n", 6);
        exit(1);
    }
}

void read_input(t_stack *stack_a, t_stack *stack_b)
{
    char *line;

    while (1)
    {
        line = get_next_line(0);
        if (!line)
            break;
        char *newline = ft_strchr(line, '\n');
        if (newline)
            *newline = '\0';
        printf("Command: %s\n", line);
        execute_input(line, stack_a, stack_b);
        printf("Stack A after %s: ", line);
        print_stack(stack_a);
        printf("Stack B after %s: ", line);
        print_stack(stack_b);
        
        free(line);
    }
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
