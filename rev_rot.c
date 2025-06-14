/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:12:37 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 13:14:14 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_stack_last(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}
void	rev_rotate_a_stack(t_node **a_stack)
{
	rev_rotate(a_stack);
	write(1, "rra\n", 4);
}
void	rev_rotate_b_stack(t_node **b_stack)
{
	rev_rotate(b_stack);
	write(1, "rrb\n", 4);
}
void	rev_rotate_both(t_node **a_stack, t_node **b_stack)
{
	rev_rotate(a_stack);
	rev_rotate(b_stack);
	write(1, "rrr\n", 4);
}
