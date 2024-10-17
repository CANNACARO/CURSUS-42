# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 18:08:20 by jcaro-lo          #+#    #+#              #
#    Updated: 2024/10/17 20:15:37 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk
RM = rm -rf
CFILES = client.c server.c minitalk_utils.c
OFILES = $(CFILES:.c=.o)
BONUS_FILES = client_bonus.c server_bonus.c minitalk_utils_bonus.c
BONUS_OFILES = $(BONUS_FILES:.c=.o)

all: $(NAME) bonus

$(NAME): client server

client: minitalk_utils.o client.o
	$(CC) $(CFLAGS) $^ -o client

server: minitalk_utils.o server.o
	$(CC) $(CFLAGS) $^ -o server

bonus: client_bonus server_bonus

client_bonus: minitalk_utils_bonus.o client_bonus.o
	$(CC) $(CFLAGS) $^ -o client_bonus

server_bonus: minitalk_utils_bonus.o server_bonus.o
	$(CC) $(CFLAGS) $^ -o server_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OFILES) $(BONUS_OFILES)

fclean: clean
	$(RM) client server client_bonus server_bonus
	
re: fclean all

.PHONY: all clean fclean re server client bonus client_bonus server_bonus