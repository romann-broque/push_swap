# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2023/02/06 15:22:12 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
#### ENV ####
#############

SHELL = /usr/bin/bash

##############
#### NAME ####
##############

NAME = push_swap
NAME_BONUS = checker
DEFAULT_ARG = 1 0 3 4

##############
#### SRCS ####
##############

PATH_SRCS += srcs/
PATH_SRCS += srcs/dualstack/
PATH_SRCS += srcs/dualstack/list/
PATH_SRCS += srcs/dualstack/stack/
PATH_SRCS += srcs/operations/
PATH_SRCS += srcs/parser/
PATH_SRCS += srcs/sort/
PATH_SRCS += srcs/sort/bin_tree/

# srcs/

SRCS += push_swap.c

# srcs/dualstack/

SRCS += print_dualstack.c
SRCS += print_instructions.c
SRCS += fact_instructions.c
SRCS += dualstack_utils.c

# srcs/dualstack/list/

SRCS += gen_list.c
SRCS += list_utils.c

# srcs/dualstack/stack/

SRCS += set_rank_stack.c
SRCS += stack_utils.c
SRCS += get_data.c

# srcs/operations/

SRCS += swap.c
SRCS += push.c
SRCS += rotate.c
SRCS += rev_rotate.c

# srcs/sort/

SRCS += is_sorted.c
SRCS += sort_dualstack.c
SRCS += tree_sort.c
SRCS += rank_sort.c

# srcs/sort/bin_tree/

SRCS += tree_utils.c

# srcs/parser/

SRCS += parsing_nb.c

### BONUS ###

PATH_SRCS_BONUS += checker_dir/srcs
PATH_SRCS_BONUS += checker_dir/srcs/operations

# checker_dir/srcs

SRCS_BONUS += checker.c
SRCS_BONUS += read_instructions.c

# checker_dir/operations

SRCS_BONUS += push_fct.c
SRCS_BONUS += swap_fct.c
SRCS_BONUS += rotate_fct.c
SRCS_BONUS += rev_rotate_fct.c

ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
	PATH_SRCS += $(PATH_SRCS_BONUS)
endif

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS = objs
OBJS_MAND = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS_BONUS))
OBJS += $(OBJS_MAND)
OBJS += $(OBJS_BONUS)

#############
#### LIB ####
#############

LIB_FOLDER = libft/
LIBFT = $(LIB_FOLDER)/libft.a
BONUS_LIB = libbonus.a

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
CHECK_INCLUDES += -I checker_dir/includes/
INCLUDES += -I includes/
INCLUDES += $(INCLUDES_LIB)

ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
	INCLUDES += $(CHECK_INCLUDES)
endif

#################
#### HEADERS ####
#################

vpath %.h $(INCLUDES)

##################
#### MAKEFILE ####
##################

MAKEFILE = Makefile

###############
#### TESTS ####
###############

TEST_FOLDER = tests/
RUN_TESTS = $(TEST_FOLDER)run_tests

#####################
#### COMPILATION ####
#####################

CC = cc

CFLAGS += -Wall
CFLAGS += -Wextra

ifneq ($(noerror), 1)
	CFLAGS += -Werror
endif

ifeq ($(everything), true)
	CFLAGS += -Weverything
endif

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############
#### RULES ####
###############

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_MAND)
	$(CC) $(CFLAGS) $(OBJS_MAND) -o $(NAME) $(INCLUDES) $(LINKS) $(LIBFT)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(LIBFT):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIB_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(OBJS_MAND): $(PATH_OBJS)/%.o: %.c $(HEADERS) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -O3

$(NAME_BONUS): $(BONUS_LIB) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(INCLUDES) $(LINKS) $(LIBFT) $(BONUS_LIB)
	$(ECHOC) $(GREEN) "--> $(NAME_BONUS) COMPILED !"$(NC)"\n\n"

$(OBJS_BONUS): $(PATH_OBJS)/%.o: %.c $(HEADERS) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -O3

$(BONUS_LIB):
	cp $(LIBFT) $(BONUS_LIB)
	ar rs $(BONUS_LIB) $(OBJS_MAND)

bonus: all $(NAME_BONUS)
	./$(NAME_BONUS)

run:
	$(MAKE) -s
	./$(NAME) $(DEFAULT_ARG)

norm:
	norminette $(PATH_SRCS) $(INCLUDES) $(LIB_FOLDER)

test:
	$(MAKE) -s
	$(MAKE) -sC $(TEST_FOLDER)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean > /dev/null
	$(MAKE) -sC $(TEST_FOLDER) clean > /dev/null
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(MAKE) -sC $(LIB_FOLDER) fclean > /dev/null
	$(MAKE) -sC $(TEST_FOLDER) fclean > /dev/null
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(BONUS_LIB)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(NAME_BONUS) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(BONUS_LIB) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(RUN_TESTS) deleted !"$(NC)"\n"

re: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re run bonus
.SILENT: $(NAME) $(NAME_BONUS) $(LIBFT) $(OBJS) $(BONUS_LIB) run clean fclean re test bonus

#endif
