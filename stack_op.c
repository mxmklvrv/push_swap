/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:36:13 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/11 18:32:00 by mklevero         ###   ########.fr       */
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

void	ft_add_node(t_node **stack, int nbr, char **av, bool splitted)
{
	t_node	*new_current_node;
	t_node	*last_node;

	if (stack == NULL)
		return ;
	new_current_node = malloc(sizeof(t_node));
	if (new_current_node == NULL)
		free_and_error(stack, av, splitted);
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
		check_validity(av, i, a_stack, splitted);
		nbr = ft_atol(av[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			free_and_error(a_stack, av, splitted);
		check_duplicate(av, a_stack, nbr, splitted);
		ft_add_node(a_stack, (int)nbr, av, splitted);
		i++;
	}
	if (splitted == true)
		free_splitted(av); // probably need to free it after the sort check
}
int	stack_len(t_node *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}