# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 10:03:51 by ttsubo            #+#    #+#              #
#    Updated: 2025/02/15 15:43:46 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC 		= cc -Wall -Wextra -Werror

#libft
LIBFT	= _libft.a

#ft_printf
PTF		= libftprintf.a
PTF_DIR	= ft_printf/

#get_next_line
GNL_DIR = get_next_line/

SRCS	= 	ft_atoi.c     ft_isdigit.c  ft_memmove.c     ft_split.c     ft_strlcpy.c  ft_strtrim.c	\
			ft_bzero.c    ft_isprint.c  ft_memset.c      ft_strchr.c    ft_strlen.c   ft_substr.c	\
			ft_calloc.c   ft_itoa.c     ft_putchar_fd.c  ft_strdup.c    ft_strmapi.c  ft_tolower.c	\
			ft_isalnum.c  ft_memchr.c   ft_putendl_fd.c  ft_striteri.c  ft_strncmp.c  ft_toupper.c	\
			ft_isalpha.c  ft_memcmp.c   ft_putnbr_fd.c   ft_strjoin.c   ft_strnstr.c				\
			ft_isascii.c  ft_memcpy.c   ft_putstr_fd.c   ft_strlcat.c   ft_strrchr.c				\
			$(GNL_DIR)get_next_line.c	$(GNL_DIR)get_next_line_utils.c								\
			ft_max.c	  ft_min.c		ft_abs.c	ft_strnlen.c	ft_strlen_until.c

BONUS_S = 	ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c		\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c

ifeq ($(MAKECMDGOALS), debug)
	CC := gcc -Wall -Wextra -Werror -g
    SRCS := $(SRCS)$(BONUS_S)
endif
ifeq ($(MAKECMDGOALS), bonus)
    SRCS := $(SRCS)$(BONUS_S)
endif

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(BONUS_S:.c=.o)

all		: common
debug	: common
bonus	: common

common : init $(NAME)

$(NAME): $(LIBFT) $(PTF_DIR)$(PTF)
	echo "Merging $(PTF) into $(NAME)..."
	mkdir -p lib_tmp
	cd lib_tmp && ar x ../$(PTF_DIR)$(PTF)
	cd lib_tmp && ar x ../$(LIBFT)
	ar rcs $(NAME) lib_tmp/*.o
	rm -rf lib_tmp
		
$(LIBFT): $(OBJS)
	ar rc $@ $^

$(PTF_DIR)$(PTF):
	$(MAKE) -C $(PTF_DIR)

init:
	@if git submodule status | grep -q '^-'; then \
		echo "Updating git submodules..."; \
		git submodule update --init; \
	else \
		echo "Submodules are already up to date."; \
	fi

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	$(MAKE) -C $(PTF_DIR) clean
	rm -f $(OBJS) $(B_OBJS)
	rm -f $(LIBFT)

fclean: clean
	$(MAKE) -C $(PTF_DIR) fclean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus common init debug
