/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:36:13 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/05 20:14:07 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stack_last(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_add_node(t_node **stack, int nbr)
{
	t_node	*new_current_node;
	t_node	*last_node;

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
			error_and_free(a_stack, av, splitted);
		ft_check_duplicate(av, *a_stack, nbr, splitted);
		ft_add_node(a_stack, (int)nbr);
		i++;
	}
	if (splitted == true)
		free_splitted(av);
}
