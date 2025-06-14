/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:11:28 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 13:14:19 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = ft_stack_last(*stack);
	*stack = first->next;
	(*stack)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}
void	rotate_a_stack(t_node **a_stack)
{
	rotate(a_stack);
	write(1, "ra\n", 3);
}
void	rotate_b_stack(t_node **b_stack)
{
	rotate(b_stack);
	write(1, "rb\n", 3);
}
void	rotate_both(t_node **a_stack, t_node **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
