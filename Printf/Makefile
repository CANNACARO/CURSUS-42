# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:56:49 by jcaro-lo          #+#    #+#              #
#    Updated: 2024/07/12 20:47:51 by jcaro-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_print_char.c ft_print_hexa_lower.c ft_print_hexa_upper.c ft_print_int.c\
	ft_print_ptr.c ft_print_string.c ft_print_unsigint.c ft_printf.c
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

all:$(NAME)

$(NAME):$(OFILES)
	ar rcs $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re