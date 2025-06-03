/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:24:05 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/03 17:44:59 by mklevero         ###   ########.fr       */
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
	if (check_input(ac, av) == 0)
		error_message (1); // need to add error message.
	else
	{	
		if (ac == 2)
		{
			av = ft_split(av[1], ' ');
			if (av == NULL)
				return (NULL); // return null for now,
		}
		else
			av = av + 1;
	}
	ft_create_stack(&a_stack, av);
	
}


int check_input(int ac, char **av)
{
	if (ac == 2)
	{
		if (confirm_single(av[1]) == 0)
			return (0);
		return (1);												
	}
	else
	{
		if (confirm_multiple(ac, av) == 0)
			return (0);
		return (1);
	}
}

int confirm_single(char *str)
{
	int i;
	
	i = 0;
	if (str[0] == '\0')
		return (0);
	while(str[i])
	{
		while(ft_isspace(str[i]))
			i++;
		if(str[i] == '+' || str[i] == '-')
			i++;
		if(!ft_isdigit(str[i]))
			return (0);
		while(ft_isdigit(str[i]))
			i++;
		if(str[i] && !ft_isspace(str[i]))
			return (0);
	}
	return (1);
}
int confirm_multiple(int ac, char **av)
{
	int i;
	long number;
	
	i = 1;
	while(i < ac)
	{
		if(confirm_single(av[i]) == 0)
			return (0);
		else
		{
			number = ft_atoi(av[i]);
			if(number < INT_MIN ||number > INT_MAX)
				return (0);
		}
		i++;
	}
	return (1);
}


int ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}


void ft_create_stack(t_node **a_stack, char **av)
{
	
	
}

