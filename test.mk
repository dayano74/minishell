# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dayano <dayano@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:48:18 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/17 11:25:29 by dayano           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# usage
# make -f test.mk
# make -f test.mk clean

I_FLG = -Iinc -Ilib/libft
L_FLG = -Llib/libft -lft -lreadline


# testを追加する場合はSRCにファイル名を追加してください。
SRC = cd.c exit.c echo.c env.c unset.c
OUT = $(addprefix test_, $(SRC:.c=.out))

all: $(OUT)

test_%.out: tests/builtin/test_%.c src/builtin/%.c
	cc $^ $(L_FLG) $(I_FLG) -o $@

clean:
	rm -f test_*.out
