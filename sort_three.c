/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:05:04 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/11 13:55:52 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a_stack)
{
	t_node	*big;

	big = find_big_num(*a_stack);
	if (big == *a_stack)
		rotate_a_stack(a_stack);
	else if ((*a_stack)->next == big)
		rev_rotate_a_stack(a_stack);
	if ((*a_stack)->num > (*a_stack)->next->num)
		swap_a_stack(a_stack);
}
