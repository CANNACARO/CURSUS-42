# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 12:20:40 by jcaro-lo          #+#    #+#              #
#    Updated: 2025/09/19 12:34:43 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 
CC = cc
FLAGS = -Wall -Wextra -Werror -g 
#FLAGS += -fsanitize=thread -g
RM = rm -rf

SRC_DIR = ./srcs
OBJ_DIR = ./obj

SRC = main.c utils.c threads.c free_resources.c \
	init_structs.c routines.c sleep_n_think.c mutex.c \
	eating_action.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDES = -I./include

all: $(NAME)

$(NAME):  $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re