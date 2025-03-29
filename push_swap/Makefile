# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile 2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 10:12:07 by jcaro-lo          #+#    #+#              #
#    Updated: 2025/03/29 10:12:11 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#NAME_BONUS = 
CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT_DIR = ./libft
SRC_DIR = ./sources
#SRC_BONUS_DIR = ./sources_bonus
OBJ_DIR = ./obj
#OBJ_BONUS_DIR = ./obj_bonus

SRC = 

#SRC_BONUS = 

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))

INCLUDES = -I$(LIBFT_DIR) -I./includes
LIBS = -L$(LIBFT_DIR) -lft

all: $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

#$(NAME_BONUS): $(LIBFT_DIR)/libft.a $(OBJ_BONUS)
#	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

#$(OBJ_BONUS_DIR)/%.o:$(SRC_BONUS_DIR)/%.c
#	mkdir -p $(OBJ_BONUS_DIR)
#	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
#	$(RM) $(OBJ_BONUS_DIR)

fclean: clean
	$(RM) $(NAME)
#	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re