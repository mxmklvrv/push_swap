/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:19:47 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 17:53:22 by mklevero         ###   ########.fr       */
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
		b_stack->push_price = calculate_price(b_stack, len_a, len_b);
		b_stack = b_stack->next;
	}
}
int	calculate_price(t_node *b_stack, int len_a, int len_b)
{
	int	price_a;
	int	price_b;

	if (b_stack->above_mid == true)
		price_b = b_stack->pos;
	else
		price_b = len_b - (b_stack->pos);
	if (b_stack->target_node->above_mid == true)
		price_a = b_stack->target_node->pos;
	else
		price_a = len_a - (b_stack->target_node->pos);
	if (b_stack->above_mid == b_stack->target_node->above_mid)
	{
		if (price_b > price_a)
			return (price_b);
		else
			return (price_a);
	}
	return (price_a + price_b);
}

void	set_cheapest(t_node *b_stack)
{
	t_node	*option;

	// t_node	*tmp;
	if (b_stack == NULL)
		return ;
	// tmp = b_stack;
	// while (tmp)
	// {
	// 	tmp->cheapest = false;
	// 	tmp = tmp->next;
	// }
	option = b_stack;
	while (b_stack)
	{
		if (b_stack->push_price < option->push_price)
			option = b_stack;
		b_stack = b_stack->next;
	}
	option->cheapest = true;
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
