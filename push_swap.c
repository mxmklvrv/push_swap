/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/06 18:34:23 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("num: %d", stack->num);
		// Optional: print index too
		printf(", index: %d", stack->index);
		printf("\n");
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*a_stack;
	t_node	*b_stack;
	bool	splitted;

	splitted = false;
	a_stack = NULL;
	b_stack = NULL;
	if (ac < 2)
		return (0);
	check_empty_input(av);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (1); // function for error or smth.
		ac = ft_new_ac_count(av);
		splitted = true;
	}
	ft_create_stack(ac, av, &a_stack, splitted);
	printf("ac count =%d\n", ac);
	// check_sort(a_stack, b_stack, ac, splitted);
	printf("A stack contents:\n");
	print_stack(a_stack);
	free_stack(&a_stack);
}
