# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayano <dayano@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:48:18 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/18 16:05:23 by dayano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# usage
# make -f test.mk
# make -f test.mk clean

CC = cc -Wall -Wextra -Werror -g

SELF := $(lastword $(MAKEFILE_LIST))
MAKEFLAGS += --no-print-directory
I_FLG = -Iinc -Ilib/libft
L_FLG = -Llib/libft -lft -lreadline

# testを追加する場合はSRCにファイル名を追加してください。
SRC = cd.c exit.c echo.c env.c unset.c tokenizer.c

OUT = $(addprefix test_, $(SRC:.c=.out))

all: $(OUT)

test_%.out: tests/builtin/test_%.c src/builtin/%.c
	$(CC) $^ $(L_FLG) $(I_FLG) -o $@

test_%.out: tests/tokenizer/test_%.c
	$(CC) $^ src/tokenizer/*.c $(L_FLG) $(I_FLG) -o $@

test_unset.out: tests/builtin/test_unset.c
	$(CC) $< src/initialize.c src/builtin/*.c $(L_FLG) $(I_FLG) -o $@

test_env.out: tests/builtin/test_env.c
	$(CC) $< src/initialize.c src/builtin/*.c $(L_FLG) $(I_FLG) -o $@

clean:
	rm -f test_*.out

re:
	$(MAKE) -f $(SELF) clean
	$(MAKE) -f $(SELF) all

.PHONY: all clean re
