/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:19:47 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/13 17:28:51 by mklevero         ###   ########.fr       */
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
t_node	*find_small_num(t_node *stack)
{
	t_node	*small;

	if (!stack)
		return (NULL);
	small = stack;
	while (stack)
	{
		if (stack->num < small->num)
			small = stack;
		stack = stack->next;
	}
	return (small);
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

void	prep_nodes(t_node *a_stack, t_node *b_stack)
{
	set_pos(a_stack);
	set_pos(b_stack);
	set_target(a_stack, b_stack);
	set_price(a_stack, b_stack);
	set_cheapest(b_stack);
}

void	set_pos(t_node *stack)
{
	int	i;
	int	mid;

	if (stack == NULL)
		return ;
	mid = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->pos = i;
		if (i <= mid)
			stack->above_mid = true;
		else
			stack->above_mid = false;
		stack = stack->next;
		i++;
	}
}
void	set_target(t_node *a_stack, t_node *b_stack)
{
	t_node	*a;
	t_node	*target_in_a;
	t_node	*small;

	small = find_small_num(a_stack);
	while (b_stack)
	{
		target_in_a = NULL;
		a = a_stack;
		while (a)
		{
			if (a->num > b_stack->num)
			{
				if (target_in_a == NULL || a->num < target_in_a->num)
					target_in_a = a;
			}
			a = a->next;
		}
		if (target_in_a)
			b_stack->target_node = target_in_a;
		else
			b_stack->target_node = small;
		b_stack = b_stack->next;
	}
}

void	set_price(t_node *a_stack, t_node *b_stack)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a_stack);
	len_b = stack_len(b_stack);
	while (b_stack)
	{
		b_stack->push_price = b_stack->pos;
		if (b_stack->above_mid == false)
			b_stack->push_price = len_b - (b_stack->pos);
		if (b_stack->target_node->above_mid == true)
			b_stack->push_price += b_stack->target_node->pos;
		else
			b_stack->push_price += len_a - (b_stack->target_node->pos);
		b_stack = b_stack->next;
	}
}

void	set_cheapest(t_node *b_stack)
{
	t_node	*option;

	if (b_stack == NULL)
		return ;
	option = b_stack;
	while (b_stack)
	{
		if (b_stack->push_price < option->push_price)
			option = b_stack;
		b_stack = b_stack->next;
	}
	option->cheapest = true;
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

t_node	*find_cheapest(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
