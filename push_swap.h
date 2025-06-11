/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:19 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/11 11:48:27 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h> // need to remove
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				index;

	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*previous;

}					t_node;

// test functions below, need to remove
void				print_stack(t_node *stack);
// test functions om top, need to remove

// check_functions
void				check_empty_input(char **av);
void				check_validity(char **av, int i, t_node **a_stack,
						bool splitted);
void				check_duplicate(char **av, t_node **a_stack, long nbr,
						bool splitted);
void				check_sort(t_node *a_stack, t_node *b_stack);
bool				is_sorted(t_node *stack);

// free
void				free_splitted(char **arr);
void				free_stack(t_node **stack);
void				free_and_error(t_node **a_stack, char **av, bool splitted);
void				error_exit(void);

// ft_basic_utils
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_new_ac_count(char **av);
long				ft_atol(const char *nptr);

// split
char				**ft_split(char const *s, char c);

// main
int					main(int ac, char **av);

// stack_op
t_node				*ft_stack_last(t_node *stack);
void				ft_add_node(t_node **stack, int nbr, char **av,
						bool splitted);
void				ft_create_stack(int ac, char **av, t_node **a_stack,
						bool splitted);

// movement
void				swap_a_stack(t_node **a_stack);
void				swap_b_stack(t_node **b_stack);
void				swap_both(t_node **a_stack, t_node **b_stack);
void				rotate_a_stack(t_node **a_stack);
void				rotate_b_stack(t_node **b_stack);
void				rotate_both(t_node **a_stack, t_node **b_stack);
void				rev_rotate_a_stack(t_node **a_stack);
void				rev_rotate_b_stack(t_node **b_stack);
void				rev_rotate_both(t_node **a_stack, t_node **b_stack);
void				push_a_stack(t_node **a_stack, t_node **b_stack);
void				push_b_stack(t_node **a_stack, t_node **b_stack);

#endif
