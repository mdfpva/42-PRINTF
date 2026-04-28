# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mide-fre <mide-fre@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/28 15:04:20 by mide-fre          #+#    #+#              #
#    Updated: 2026/04/28 15:18:13 by mide-fre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs
INC_DIR = include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

SRC_FILES = ft_printf.c ft_print.c ft_putchar.c ft_puthex.c \
			ft_putnbr.c ft_putptr.c ft_putstr.c ft_putui.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
