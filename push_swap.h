/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:19:19 by mklevero          #+#    #+#             */
/*   Updated: 2025/06/04 16:45:18 by mklevero         ###   ########.fr       */
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

// ft_basics
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_new_ac_count(char **av);

// split
char				**ft_split(char const *s, char c);

#endif
