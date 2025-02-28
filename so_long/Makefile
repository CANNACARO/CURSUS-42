# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 10:38:06 by jcaro-lo          #+#    #+#              #
#    Updated: 2025/02/23 12:52:15 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ofast
RM = rm -rf

LIBFT_DIR = ./libft
MLX42_DIR = ./MLX42
SRC_DIR = ./sources
OBJ_DIR = ./obj

SRC = so_long.c tools.c parse_map.c check_path.c check_map_tools.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDES = -I$(MLX42_DIR)include -I$(LIBFT_DIR) -I./includes
LIBS = -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(MLX42_DIR)/build/libmlx42.a $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42_DIR)/build/libmlx42.a:
	mkdir -p $(MLX42_DIR)/build
	cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	cmake --build $(MLX42_DIR)/build -j4

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)
	$(RM) $(MLX42_DIR)/build

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re