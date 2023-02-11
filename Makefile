# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 12:01:05 by mmaythaw          #+#    #+#              #
#    Updated: 2023/02/11 13:55:34 by mmaythaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# VARIABLES

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCM_DIR = srcm
SRCB_DIR = srcb
OBJM_DIR = objm
OBJB_DIR = objb
FT_PRINTF = ft_printf/libftprintf.a
PRINTF = LC_NUMERIC="en_US.UTF-8" printf

SRCM = input_check.c find.c main.c place.c sort_stack.c hundred_sort.c operation.c \
       quick_sort_arr.c stack_creation.c parse_chunk.c rotation.c
SRCB = input_check_bonus.c checker.c get_next_line_utils.c stack_creation_bonus.c \
       result_check.c get_next_line.c operation_bonus.c

OBJM = $(addprefix $(OBJM_DIR)/, $(SRCM:.c=.o))
OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

# COMMANDS
SRCM_COUNT_TOT := $(shell expr $(shell echo -n $(SRCM) | wc -w) - $(shell ls -l $(OBJM_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCM_COUNT_TOT) -le 0; echo $$?),0)
	SRCM_COUNT_TOT := $(shell echo -n $(SRCM) | wc -w)
endif
SRCM_COUNT := 0
SRCM_PCT = $(shell expr 100 \* $(SRCM_COUNT) / $(SRCM_COUNT_TOT))

SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
 ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs compile_printf $(OBJM)
	@$(CC) $(CFLAGS) -o $@ $(FT_PRINTF) $(OBJM)
	@$(PRINTF) "\r%100s\r$(GREEN)$@ is up to date!$(DEFAULT)\n"

$(OBJM_DIR)/%.o: $(SRCM_DIR)/%.c
	@$(eval SRCM_COUNT = $(shell expr $(SRCM_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCM_COUNT) $(SRCM_COUNT_TOT) $(SRCM_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs compile_printf $(OBJB)
	@$(CC) $(CFLAGS) -o checker $(FT_PRINTF) $(OBJB)
	@$(PRINTF) "\r%100s\r$(GREEN)checker is up to date!$(DEFAULT)\n"

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@$(PRINTF) "$(YELLOW)\r%100s\r[ %d/%d (%d%%) ] $(WHITE)Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

compile_printf:
	@make bonus -C ft_printf

create_dirs:
	@mkdir -p $(OBJM_DIR)
	@mkdir -p $(OBJB_DIR)

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in push_swap...$(DEFAULT)\n"
	@if [ -d "ft_printf" ]; then make clean -C ft_printf; fi
	@$(RM) -r $(OBJM_DIR)
	@$(RM) -r $(OBJB_DIR)

fclean: clean
	@$(RM) -r $(NAME)
	@$(RM) -r checker
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@if [ -d "ft_printf" ]; then $(RM) -f $(FT_PRINTF); fi
	@if [ ! -d "ft_printf" ]; then $(PRINTF) "$(CYAN)Removed libftprintf.a$(DEFAULT)\n"; fi

re: fclean all

.PHONY: all clean fclean re $(NAME) bonus compile_printf create_dirs
