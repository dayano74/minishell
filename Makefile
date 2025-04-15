# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 12:55:20 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/15 17:00:54 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc

SRC_DIR 			= src/
TOKENIZER_SRC_DIR	= src/tokenizer/
BUILTIN_SRC_DIR		= src/builtin/
INC_DIR 			= inc/
OBJ_DIR 			= obj/
FT_DIR  			= lib/libft/

MAKEFLAGS += --no-print-directory
W_FLG = -Wall -Wextra -Werror
I_FLG = -I$(INC_DIR) -I$(FT_DIR)
L_FLG = -lreadline -lft

SRC	 		= main.c minish_signal.c
TOKENIZER_SRC = tokenizer.c tokenizer_error.c read_token.c \
				is_quote_closed.c get_token_capa.c
BUILTIN_SRC = cd.c exit.c pwd.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS += $(addprefix $(TOKENIZER_SRC_DIR), $(TOKENIZER_SRC))
SRCS += $(addprefix $(BUILTIN_SRC_DIR), $(BUILTIN_SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(TOKENIZER_SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(BUILTIN_SRC:.c=.o))

LIBFT=libft.a

all: $(NAME)

$(NAME): $(FT_DIR)$(LIBFT) $(OBJS)
	$(CC) $(W_FLG) $(OBJS) -L$(FT_DIR) $(L_FLG) -o $(NAME)

$(FT_DIR)$(LIBFT):
	$(MAKE) -C $(FT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@ 

$(OBJ_DIR)%.o: $(TOKENIZER_SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@ 

$(OBJ_DIR)%.o: $(BUILTIN_SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@ 

clean:
	$(MAKE) -C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)*.o

fclean:
	$(MAKE) -C $(FT_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re