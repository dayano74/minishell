# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:48:18 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/14 21:01:49 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# usage
# make -f test.mk
# make -f test.mk clean

I_FLG = -Iinc -Ilib/libft 
L_FLG = -Llib/libft -lft -lreadline

# 
SRC = cd.c exit.c

all:
	cc tests/builtin/test_cd.c src/builtin/cd.c -Llib/libft -lft -Iinc -Ilib/libft -o test_cd.out
	cc tests/builtin/test_exit.c src/builtin/exit.c -Ilib/libft -Llib/libft -lft -Iinc -lreadline -o test_exit

clean:
	rm -f test_cd.out
	rm -f test_exit