# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 12:55:20 by ttsubo            #+#    #+#              #
#    Updated: 2025/04/25 18:21:35 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc

SRC_DIR 			= src/
PARSER_SRC_DIR		= src/parser/
TOKENIZER_SRC_DIR	= src/tokenizer/
INVOKE_CMD_SRC_DIR	= src/invoke_cmd/
BUILTIN_SRC_DIR		= src/builtin/
INC_DIR 			= inc/
OBJ_DIR 			= obj/
FT_DIR  			= lib/libft/

MAKEFLAGS += --no-print-directory
W_FLG = -Wall -Wextra -Werror
I_FLG = -I$(INC_DIR) -I$(FT_DIR)
L_FLG = -lreadline -lft

SRC	 		=	main.c minish_signal.c initialize.c
INVOKE_CMD_SRC = create_envp.c  exec_pipeline.c  execute_cmd.c \
				execute_cmd_helper.c  invoke_command.c pipeline_helper.c
TOKENIZER_SRC = tokenizer.c tokenizer_error.c read_token.c \
				is_quote_closed.c get_token_capa.c is_redirect_validate.c
PARSER_SRC	=	allocate_cmds.c  parser.c  parser_utils.c  setup_cmds.c
BUILTIN_SRC	=	cd.c exit.c pwd.c echo.c env.c unset.c \
				env_utils.c env_utils_2.c builtin_utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS += $(addprefix $(PARSER_SRC_DIR), $(PARSER_SRC))
SRCS += $(addprefix $(TOKENIZER_SRC_DIR), $(TOKENIZER_SRC))
SRCS += $(addprefix $(INVOKE_CMD_SRC_DIR), $(INVOKE_CMD_SRC))
SRCS += $(addprefix $(BUILTIN_SRC_DIR), $(BUILTIN_SRC))
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(PARSER_SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(TOKENIZER_SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(INVOKE_CMD_SRC:.c=.o))
OBJS += $(addprefix $(OBJ_DIR), $(BUILTIN_SRC:.c=.o))

LIBFT=libft.a

all: $(NAME)

$(NAME): $(FT_DIR)$(LIBFT) $(OBJS)
	$(CC) $(W_FLG) $(OBJS) -L$(FT_DIR) $(L_FLG) -o $(NAME)

$(FT_DIR)$(LIBFT):
	$(MAKE) -C $(FT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@

$(OBJ_DIR)%.o: $(PARSER_SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@

$(OBJ_DIR)%.o: $(TOKENIZER_SRC_DIR)%.c
	$(CC) $(W_FLG) $(I_FLG) -c $< -o $@

$(OBJ_DIR)%.o: $(INVOKE_CMD_SRC_DIR)%.c
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
