/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:19:47 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/11 15:59:11 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_big_num(t_node *stack)
{
	t_node	*big;

	if (!stack)
		return (NULL);
	big = stack;
	while (stack)
	{
		if (stack->num > big->num)
			big = stack;
		stack = stack->next;
	}
	return (big);
}
