/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:44:42 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/14 15:44:56 by mklevero         ###   ########.fr       */
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

void	check_sort(t_node **a_stack, t_node **b_stack) // not sure
{
	if (!is_sorted(*a_stack))
	{
		if (stack_len(*a_stack) == 2)
			swap_a_stack(a_stack);
		else if (stack_len(*a_stack) == 3)
			sort_three(a_stack);
		else
			turk_sort(a_stack, b_stack);
	}
	free_stack(a_stack);
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
