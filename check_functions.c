/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:44:42 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/06 13:59:47 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_empty_input(char **av)
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
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
void	ft_check_validity(char **av, int i, t_node **a_stack, bool splitted)
{
	int	m;

	m = 0;
	if ((av[i][m] == '-' || av[i][m] == '+') && ft_isdigit(av[i][m + 1]))
		m++;
	while (av[i][m] != '\0')
	{
		if (!ft_isdigit(av[i][m]))
			error_and_free(a_stack, av, splitted);
		m++;
	}
}

void	ft_check_duplicate(char **av, t_node **a_stack, long nbr, bool splitted)
{
	t_node	*temp;
	if(a_stack == NULL)
		return ; // think here 
	if(*a_stack == NULL)
		return ;
	temp = *a_stack;
	while (temp != NULL)
	{
		if(temp->num == nbr)
			error_and_free(a_stack, av, splitted);
		temp = temp->next;
	} 
}