/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:05:04 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 13:22:23 by mklevero         ###   ########.fr       */
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
void	turk_sort(t_node **a_stack, t_node **b_stack)
{
	int		len;
	t_node	*small;

	len = stack_len(*a_stack);
	while (len-- > 3)
		push_b_stack(b_stack, a_stack);
	sort_three(a_stack);
	while (*b_stack)
	{
		prep_nodes(*a_stack, *b_stack);
		push_back(a_stack, b_stack);
	}
	set_pos(*a_stack);
	small = find_small_num(*a_stack);
	if (small->above_mid)
	{
		while (*a_stack != small)
			rotate_a_stack(a_stack);
	}
	else
		while (*a_stack != small)
			rev_rotate_a_stack(a_stack);
}

void	push_back(t_node **a_stack, t_node **b_stack)
{
	t_node	*cheapest;
	t_node	*tg_in_a;

	cheapest = find_cheapest(*b_stack);
	tg_in_a = cheapest->target_node;
	while (*a_stack != tg_in_a && *b_stack != cheapest)
	{
		if (tg_in_a->above_mid && cheapest->above_mid)
			rotate_both(a_stack, b_stack);
		else if (!tg_in_a->above_mid && !cheapest->above_mid)
			rev_rotate_both(a_stack, b_stack);
		else
			break ;
	}
	set_pos(*a_stack);
	set_pos(*b_stack);
	final_touch(a_stack, b_stack, cheapest, tg_in_a);
	push_a_stack(a_stack, b_stack);
}

void	final_touch(t_node **a_stack, t_node **b_stack, t_node *cheapest,
		t_node *tg_in_a)
{
	while (*a_stack != tg_in_a)
	{
		if (tg_in_a->above_mid)
			rotate_a_stack(a_stack);
		else
			rev_rotate_a_stack(a_stack);
	}
	while (*b_stack != cheapest)
	{
		if (cheapest->above_mid)
			rotate_b_stack(b_stack);
		else
			rev_rotate_b_stack(b_stack);
	}
}
