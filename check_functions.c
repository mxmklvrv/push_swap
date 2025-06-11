/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:44:42 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/11 15:59:18 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_empty_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == '\0')
			error_exit();
		i++;
	}
}
void	check_validity(char **av, int i, t_node **a_stack, bool splitted)
{
	int	m;

	m = 0;
	if (av[i][m] == '-' || av[i][m] == '+')
	{
		if (!ft_isdigit(av[i][m + 1]))
			free_and_error(a_stack, av, splitted);
		m++;
	}
	while (av[i][m] != '\0')
	{
		if (!ft_isdigit(av[i][m]))
			free_and_error(a_stack, av, splitted);
		m++;
	}
}

void	check_duplicate(char **av, t_node **a_stack, long nbr, bool splitted)
{
	t_node	*temp;

	if (a_stack == NULL || *a_stack == NULL)
		return ;
	temp = *a_stack;
	while (temp != NULL)
	{
		if (temp->num == nbr)
			free_and_error(a_stack, av, splitted);
		temp = temp->next;
	}
}

void	check_sort(t_node *a_stack, t_node *b_stack)
{
	if (!is_sorted(a_stack))
	{
		if (stack_len(a_stack) == 2)
			swap_a_stack(&a_stack);
		else if (stack_len(a_stack) == 3)
	}
}

bool	is_sorted(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// main swap function
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
// rotate function
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
// rev_rot function
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
// push function
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

void	push_b_stack(t_node **a_stack, t_node **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pb\n", 3);
}
