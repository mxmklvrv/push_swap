# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mklevero <mklevero@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 14:31:23 by mklevero          #+#    #+#              #
#    Updated: 2025/05/30 14:41:26 by mklevero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJ = $(SRCS:.c=.o)
.SECONDARY: ${OBJ}

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) &(OBJ)

%.o: %.cc
		$(CC) &(CFLAGS) -c $< -o $@

clean:
		rm -f &(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re 
