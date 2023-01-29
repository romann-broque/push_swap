# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:20:37 by rbroque           #+#    #+#              #
#    Updated: 2023/01/29 01:10:40 by rbroque          ###   ########.fr        #
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
DEFAULT_ARG = 1 0 3 4

##############
#### SRCS ####
##############

PATH_SRCS += srcs/
PATH_SRCS += srcs/list/
PATH_SRCS += srcs/operations/

# srcs/

SRCS += push_swap.c

# srcs/list/

SRCS += list_utils.c

# srcs/operations/

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

#############
#### LIB ####
#############

LIB_FOLDER = libft/
LIB = $(LIB_FOLDER)/libft.a

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
INCLUDES += includes/

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

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(LIB):
	echo -e $(BLUE) "\n====> Building libft.a <===="$(NC)"\n"
	$(MAKE) -sC $(LIB_FOLDER)
	echo -e $(BLUE) "\n====> Building $(NAME) <===="$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADERS) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) $(INCLUDES_LIB) -O3

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
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"
	$(ECHOC) $(GREEN) "--> $(RUN_TESTS) deleted !"$(NC)"\n"

re: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re run
.SILENT: $(NAME) $(LIB) $(OBJS) run clean fclean re test

#endif
