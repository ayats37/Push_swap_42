/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:59:24 by taya              #+#    #+#             */
/*   Updated: 2025/03/03 01:03:39 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bool is_sorted(t_stack *stack) {
//     if (stack->size <= 1)
//         return true;
    
//     t_node *current = stack->head;
//     while (current->next) {
//         if (current->value > current->next->value)
//             return false;
//         current = current->next;
//     }
//     return true;
// }

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->head == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	
}