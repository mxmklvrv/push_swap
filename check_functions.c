/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:44:42 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/04 19:58:05 by mklevero         ###   ########.fr       */
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
	int m;

	m = 0;
	while (av[i][m])
	{
		if ((av[i][m] == '-' || av[i][m] == '+') && ft_isdigit(av[i][m + 1]))
			m++;
		while (ft_isdigit(av[i][m]))
			m++;
		if (!ft_isdigit(av[i][m]))
			error_and_free(&a_stack, av, splitted); // need to make it
	}
}