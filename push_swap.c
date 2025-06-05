/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/05 18:07:29 by mklevero         ###   ########.fr       */
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
