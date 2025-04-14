# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Maketest.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 11:48:18 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/14 11:49:08 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cc tests/builtin/test_cd.c src/builtin/cd.c -Llib/libft -lft -Iinc -o test_cd.out

clean:
	rm -f test_cd.out