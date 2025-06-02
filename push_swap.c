/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/02 19:02:50 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returning basic values for now, will need an error message and free, etc.

int	main(int ac, char **av)
{
	t_node	*a_stack;
	t_node	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	// checking input
	if (ac < 2)
		return (0);
	if (ac == 2 && !av[1][0])
		return (0); // return 0 for now,
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (NULL); // return null for now,
	}
	else
		av = av + 1;
}
