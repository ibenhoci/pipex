# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 09:49:29 by ibenhoci          #+#    #+#              #
#    Updated: 2023/09/20 12:37:57 by ibenhoci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

OBJECTS_DIR = objects/
SOURCE_DIR = src/

SOURCE = pipex.c \
			pipex_utils.c \

FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

OBJECTS = $(SOURCE:.c=.o)
OBJS = $(addprefix $(OBJECTS_DIR), $(OBJECTS))

all: $(OBJECTS_DIR) $(NAME)

$(OBJECTS_DIR)%.o: $(SOURCE_DIR)%.c
	cc -c $< -o $@ -I pipex.h $(FLAGS)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)
	cd libft && make

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	cd libft && make clean
	rm -rf $(OBJECTS_DIR)

fclean: clean
		cd libft && make fclean
		rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
