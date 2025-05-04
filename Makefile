# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 12:55:20 by ttsubo            #+#    #+#              #
#    Updated: 2025/05/04 12:12:23 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
MAKEFLAGS += --no-print-directory
W_FLG = -Wall -Wextra -Werror
L_FLG = -lreadline -lft

HEADER_DIRS = 	lib/libft/ inc/ inc/builtin/  inc/common/ \
			inc/invoke_cmd/  inc/parser/  inc/signal/  inc/tokenizer/
I_FLG = $(addprefix -I, $(HEADER_DIRS))

# 1.Add more directories as they are added.
SRC_DIR 			= src/
PARSER_SRC_DIR		= src/parser/
COMMON_SRC_DIR		= src/common/
TOKENIZER_SRC_DIR	= src/tokenizer/
INVOKE_CMD_SRC_DIR	= src/invoke_cmd/
BUILTIN_SRC_DIR		= src/builtin/
INC_DIR 			= inc/
OBJ_DIR 			= obj/
FT_DIR  			= lib/libft/

define add_module
  $(eval UPPER := $(shell echo $(1) | tr 'a-z' 'A-Z'))
  ifeq ($(1), root)
  	SRCS += $(addprefix $(SRC_DIR), $($(UPPER)_SRC))
  else
  	SRCS += $(addprefix $(SRC_DIR)$(1)/, $($(UPPER)_SRC))
  endif
  	OBJS += $(addprefix $(OBJ_DIR)$(1)/, $($(UPPER)_SRC:.c=.o))
  	MODULE_DIRS += $(1)
endef

define define_rule
  $(eval $(1): $(2) ; \
    @mkdir -p $$(dir $$@) ; \
    $(CC) $(W_FLG) $(I_FLG) -c $$< -o $$@)
endef

TMP_LOG := .tmp_build.log

define run_step
	@echo -n "$(1)... "
	@($(2) > /dev/null 2>$(TMP_LOG)) \
		&& echo "✅" \
		|| (echo "❌" && cat $(TMP_LOG))
	@rm -f $(TMP_LOG)
endef

# 2.Add the source code when it is added
ROOT_SRC		=	main.c minish_signal.c initialize.c error.c
COMMON_SRC		=	validate_key.c error_mes.c
INVOKE_CMD_SRC	=	create_envp.c  exec_pipeline.c  execute_cmd.c \
					execute_cmd_helper.c  invoke_command.c pipeline_helper.c \
					redirect.c fds.c wait_pipeline.c
TOKENIZER_SRC	= 	tokenizer.c tokenizer_error.c read_token.c \
					is_quote_closed.c get_token_capa.c is_redirect_validate.c
PARSER_SRC		=	allocate_cmds.c  parser.c  parser_utils.c  setup_cmds.c \
					expand_env.c
BUILTIN_SRC		=	cd.c exit.c pwd.c echo.c env.c unset.c export.c \
					env_utils.c env_utils_2.c env_utils_3.c builtin_utils.c \
					export_exec.c export_print_sorted_env.c export_error.c split_key_value.c

# 3.Add more directories as they are added.
$(eval $(call add_module,root))
$(eval $(call add_module,common))
$(eval $(call add_module,invoke_cmd))
$(eval $(call add_module,tokenizer))
$(eval $(call add_module,parser))
$(eval $(call add_module,builtin))

LIBFT=libft.a
TEST=MAIN

all: $(NAME)

$(NAME): $(FT_DIR)$(LIBFT) $(OBJS)
	$(call run_step,Building $@, $(CC) $(W_FLG) $(OBJS) -L$(FT_DIR) $(L_FLG) -o $(NAME))

$(FT_DIR)$(LIBFT):
	$(call run_step,Building libft, $(MAKE) -C $(FT_DIR))

$(foreach DIR,$(MODULE_DIRS), \
  $(if $(filter $(DIR),root), \
    $(call define_rule, $(OBJ_DIR)$(DIR)/%.o, $(SRC_DIR)%.c), \
    $(call define_rule, $(OBJ_DIR)$(DIR)/%.o, $(SRC_DIR)$(DIR)/%.c) \
  ) \
)

clean:
	$(call run_step,cleaning libft, $(MAKE) -C $(FT_DIR) clean)
	$(call run_step,cleaning $(NAME) objs, \
	[ -d $(OBJ_DIR) ] && find $(OBJ_DIR) -type f -name '*.o' -exec rm -f {} + || true)
	$(call run_step,cleaning $(NAME) empty dirs, \
		[ -d $(OBJ_DIR) ] && find $(OBJ_DIR) -type d -empty -not -name '.' -exec rmdir {} + || true)

fclean:
	$(call run_step,Removing libft bin, $(MAKE) -C $(FT_DIR) fclean)
	$(MAKE) clean
	$(call run_step,Removing binary, rm -rf $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
