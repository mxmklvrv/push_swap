# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 14:31:23 by mklevero          #+#    #+#              #
#    Updated: 2025/06/05 19:08:20 by mklevero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c stack_op.c ft_split.c ft_basic_utils.c free.c \
check_functions.c

OBJ = $(SRCS:.c=.o)
.SECONDARY: ${OBJ}

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 
