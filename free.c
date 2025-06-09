/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:34:52 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/09 15:54:52 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
	printf("freed av after split\n");
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (*stack == NULL || stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}
void	free_and_error(t_node **a_stack, char **av, bool splitted)
{
	free_stack(a_stack);
	if (splitted == true)
		free_splitted(av);
	error_exit();
}
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
