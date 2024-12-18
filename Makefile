# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thessena <thessena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 09:23:28 by thessena          #+#    #+#              #
#    Updated: 2024/11/14 13:35:14 by thessena         ###   ########.fr        #
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
ft_putstr.c \
ft_putptr.c \
ft_putnbr.c \
ft_putnbr_unsigned.c \
ft_puthex_lower.c \
ft_puthex_upper.c \
ft_putperc.c


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