# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lixu <lixu@student.42madrid.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 14:23:47 by lixu              #+#    #+#              #
#    Updated: 2022/05/30 18:13:07 by lixu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRC = ft_p_char.c ft_p_str.c ft_p_hex.c ft_p_nbr.c ft_p_pct.c ft_p_ui.c ft_p_ptr.c\
ft_putchar_fd.c ft_printf.c

OBJ = $(SRC:.c=.o)
INCLUDE = ft_printf.h


all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
