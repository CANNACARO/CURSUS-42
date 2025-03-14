# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 10:38:06 by jcaro-lo          #+#    #+#              #
#    Updated: 2025/03/14 19:04:37 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT_DIR = ./libft
MLX42_DIR = ./MLX42
SRC_DIR = ./sources
SRC_BONUS_DIR = ./sources_bonus
OBJ_DIR = ./obj
OBJ_BONUS_DIR = ./obj_bonus

SRC = so_long.c tools.c parse_map.c check_path.c check_map_tools.c hook.c\
	render.c

SRC_BONUS = so_long_bonus.c tools_bonus.c parse_map_bonus.c\
	check_path_bonus.c check_map_tools_bonus.c hook_bonus.c\
	render_bonus.c images_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))

INCLUDES = -I$(MLX42_DIR)include -I$(LIBFT_DIR) -I./includes
LIBS = -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT_DIR) -lft

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(MLX42_DIR)/build/libmlx42.a $(LIBFT_DIR)/libft.a $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBS)

$(NAME_BONUS): $(MLX42_DIR)/build/libmlx42.a $(LIBFT_DIR)/libft.a $(OBJ_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o:$(SRC_BONUS_DIR)/%.c
	mkdir -p $(OBJ_BONUS_DIR)
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
	$(RM) $(OBJ_BONUS_DIR)
	$(RM) $(MLX42_DIR)/build

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re