/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:10:15 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 13:14:17 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*to_move;

	if (*src == NULL)
		return ;
	to_move = *src;
	*src = to_move->next;
	if (*src != NULL)
		(*src)->previous = NULL;
	to_move->next = NULL;
	if (*dst != NULL)
		(*dst)->previous = to_move;
	to_move->next = *dst;
	to_move->previous = NULL;
	*dst = to_move;
}
void	push_a_stack(t_node **a_stack, t_node **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pa\n", 3);
}

void	push_b_stack(t_node **b_stack, t_node **a_stack)
{
	push(b_stack, a_stack);
	write(1, "pb\n", 3);
}
