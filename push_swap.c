/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/05 16:42:19 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returning basic values for now, will need an error message and free, etc.

int	main(int ac, char **av)
{
	t_node	*a_stack;
	t_node	*b_stack;
	bool	splitted;

	a_stack = NULL;
	b_stack = NULL;
	if (ac < 2)
		return (0);
	ft_check_empty_input(av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (NULL); // function for error or smth.
		ac = ft_new_ac_count(av);
		splitted = true;
	}
	ft_create_stack(ac, av, &a_stack, splitted);
}

void	ft_create_stack(int ac, char **av, t_node **a_stack, bool splitted)
{
	int		i;
	long	nbr;

	if (splitted == true)
		i = 0;
	else
		i = 1;
	while (i < ac)
	{
		ft_check_validity(av, i, *a_stack, splitted);
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_and_free(&a_stack, av, splitted);
		ft_check_duplicate(av, *a_stack, nbr, splitted);
		ft_add_node(a_stack, (int)nbr);
	}
}

void	ft_add_node(t_node **stack, int nbr)
{
	t_node *new_current_node;
	t_node *last_node;

	if (stack == NULL)
		return ; // not sure yet.
	new_current_node = malloc(sizeof(t_node));
	if (new_current_node == NULL)
		return ; // not sure yet.
	new_current_node->next = NULL;
	new_current_node->previous = NULL;
	new_current_node->num = nbr;
	// might add smth else from t_node, like cheapest(tftm), etc..
	if (*stack == NULL)
		*stack = new_current_node;
	else
	{
		last_node = ft_stack_last(*stack);
		last_node->next = new_current_node;
		new_current_node->previous = last_node;
	}
}