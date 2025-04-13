# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 11:31:03 by ttsubo            #+#    #+#              #
#    Updated: 2024/12/08 11:53:08 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= libftprintf.a
CC 			= cc -Wall -Wextra -Werror
SRCS		= srcs/ft_printf.c	srcs/format_handler.c	srcs/format_handler2.c \
			  srcs/ft_printf_utils1.c srcs/ft_printf_utils2.c

OBJS		= $(SRCS:.c=.o)

ifeq ($(MAKECMDGOALS), debug)
	CC := cc -Wall -Wextra -Werror -g
endif

all: $(TARGET)

debug: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $< -Iincludes -o $@ 

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re debug
