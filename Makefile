# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdarkhaw <fdarkhaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 15:51:18 by fdarkhaw          #+#    #+#              #
#    Updated: 2022/01/18 13:25:28 by fdarkhaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

INC_DIR		= ./includes/
LIBFT_DIR	= ./libft/

SRCS		=	./sources/main.c\
#				./sources/
				
		
OBJ			= $(SRCS:.c=.o)
DEP			= $(SRCS:.c=.d)

CFLAGS		= -Wall -Werror -Wextra

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJ)
			@make -C $(LIBFT_DIR)
			gcc -o $(NAME) $(CFLAGS) -I$(INC_DIR) $(OBJ) $(LIBFT_DIR)libft.a

%.o : %.c
		cc -c $(CFLAGS) -I$(INC_DIR) $< -o $@ -MD
		
clean:
		rm -f $(OBJ) $(DEP)
		
fclean: clean
		rm -f $(NAME)

re: fclean all

include $(wildcard $(DEP))
