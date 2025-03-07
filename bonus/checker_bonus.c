/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:01:53 by taya              #+#    #+#             */
/*   Updated: 2025/03/07 14:54:09 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int init_stacks(int argc, char **argv, t_stack *stack_a)
{
    int value;
    int i;

    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        value = ft_atoi(argv[i]);
        if (is_duplicate(stack_a, value))
        {
            write(2, "Error\n", 6);
            return (1);
        }
        t_node *new_node = create_node(value);
        if (!new_node)
            return (1);
            
        if (stack_a->size == 0)
        {
            stack_a->head = new_node;
            stack_a->tail = new_node;
        }
        else
        {
            stack_a->tail->next = new_node;
            new_node->prev = stack_a->tail;
            stack_a->tail = new_node;
        }
        stack_a->size++; 
        i++;
    }
    return (0);
}

void print_stack(t_stack *stack)
{
    t_node *current = stack->head;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

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

    printf("Initial stack_a: ");
    print_stack(&stack_a);
    printf("Initial stack_b: ");
    print_stack(&stack_b);

    read_input(&stack_a, &stack_b);

    printf("Final stack_a: ");
    print_stack(&stack_a);
    printf("Final stack_b: ");
    print_stack(&stack_b);

    if (sorted(&stack_a) && (stack_b.size == 0))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
