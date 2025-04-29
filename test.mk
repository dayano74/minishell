# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:48:18 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/29 13:51:31 by ttsubo           ###   ########.fr        #
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
SRC = cd.c exit.c echo.c env.c unset.c tokenizer.c export.c

OUT = $(addprefix test_, $(SRC:.c=.out))

all: $(OUT)

test_%.out: tests/builtin/test_%.c src/builtin/%.c
	$(CC) $^ src/builtin/builtin_utils.c $(L_FLG) $(I_FLG) -o $@

test_%.out: tests/tokenizer/test_%.c
	$(CC) $^ src/tokenizer/*.c $(L_FLG) $(I_FLG) -o $@

test_export.out: tests/builtin/test_export.c
	$(CC) $< src/initialize.c src/builtin/*.c src/common/*.c $(L_FLG) $(I_FLG) -o $@

test_%.out: tests/parser/test_%.c
	$(CC) $^ src/parser/*.c src/tokenizer/*.c src/builtin/*.c src/initialize.c $(L_FLG) $(I_FLG) -o $@

test_unset.out: tests/builtin/test_unset.c
	$(CC) $< src/initialize.c src/builtin/*.c src/common/*.c $(L_FLG) $(I_FLG) -o $@

test_env.out: tests/builtin/test_env.c
	$(CC) $< src/initialize.c src/builtin/*.c src/common/*.c $(L_FLG) $(I_FLG) -o $@

test_create_envp.out: tests/invoke_cmd/test_create_envp.c
	$(CC) $< src/initialize.c src/invoke_cmd/create_envp.c src/builtin/*.c $(L_FLG) $(I_FLG) -o $@

clean:
	rm -f test_*.out

re:
	$(MAKE) -f $(SELF) clean
	$(MAKE) -f $(SELF) all

.PHONY: all clean re
