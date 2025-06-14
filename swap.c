/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:08:41 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 17:43:34 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->previous = first->previous;
	if (second->next != NULL)
		second->next->previous = first;
	first->previous = second;
	second->next = first;
	*stack = second;
}

void	swap_a_stack(t_node **a_stack)
{
	swap(a_stack);
	write(1, "sa\n", 3);
}
void	swap_b_stack(t_node **b_stack)
{
	swap(b_stack);
	write(1, "sb\n", 3);
}
void	swap_both(t_node **a_stack, t_node **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}
