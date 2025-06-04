/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:19 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/04 19:58:20 by mklevero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				index;

	struct s_node	*target_node;
	struct s_node	*next;

}					t_node;

// input validation
void				ft_check_empty_input(char **av);
void				ft_check_validity(char **av, int i, t_node **a_stack,
						bool splitted);

// ft_basics
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_new_ac_count(char **av);
long				ft_atol(const char *nptr);

// split
char				**ft_split(char const *s, char c);

// lists
void				ft_create_stack(int ac, char **av, t_node **a_stack,
						bool splitted);

#endif
