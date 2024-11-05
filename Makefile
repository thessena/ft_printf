# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thessena <thessena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 09:23:28 by thessena          #+#    #+#              #
#    Updated: 2024/11/05 13:13:57 by thessena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc
CFLAGS= -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf
MKDIR = mkdir -p

SOURCES = \
ft_printf.c \
ft_putchar.c \
ft_putnbr.c \
ft_putperc.c \
ft_putstr.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re