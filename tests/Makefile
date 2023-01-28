# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 12:11:15 by rbroque           #+#    #+#              #
#    Updated: 2023/01/15 17:45:44 by rbroque          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
#### ENV ####
#############

SHELL = /usr/bin/bash

##############
#### NAME ####
##############

NAME = run_tests

##############
#### SRCS ####
##############

PATH_SRCS += srcs/

# srcs/

SRCS += main.c
SRCS += test_utils.c
SRCS += parser.test.c
#SRCS += put_pixel.test.c

vpath %.c $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS = objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

FDF_CMPL = $(wildcard ../objs/*.o)
FDF_OBJS = $(filter-out ../objs/main.o,$(FDF_CMPL))

#############
#### LIB ####
#############

LIB_FOLDER = ../libft/
LIB = $(LIB_FOLDER)/libft.a

LIB_FDF = libfdf.a

###################
#### INCLUDES #####
###################

INCLUDES_LIB += -I $(LIB_FOLDER)/includes/
INCLUDES_LIB += -I /usr/include/X11/
INCLUDES_LIB += -I ../minilibx-linux/
INCLUDES += ../includes/
TEST_INCLUDES += includes/

MINILIBX += ../minilibx-linux/libmlx_Linux.a
LINKS += -L/usr/lib -lXext -lX11 -lm -lz
HEADER += $(INCLUDES)/fdf.h
TEST_HEADER += $(TEST_INCLUDES)/run_tests.h

##################
#### MAKEFILE ####
##################

MAKEFILE = Makefile

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

all: $(NAME)
	$(ECHOC) $(BLUE)"\n""CLASSIC TESTS"$(NC)"\n"
	./$(NAME)
#	$(ECHOC) $(BLUE)"\n""MLX_CRASH TESTS"$(NC)"\n"
#	env -i ./$(NAME)

$(NAME): $(LIB_FDF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME) -I $(INCLUDES) $(INCLUDES_LIB) $(LINKS) $(LIB_FDF) $(LIB) $(MINILIBX)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(LIB_FDF):
	echo -e $(BLUE) "\n====> Building tests <===="$(NC)"\n"
	echo -e $(BLUE) "\n====> Building libfdf.a"$(NC)"\n"
	ar rcs $(LIB_FDF) $(FDF_OBJS)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n"
	echo -e $(BLUE) "\n====> Building $(NAME)"$(NC)"\n"

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(TEST_HEADER) $(MAKEFILE)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(TEST_INCLUDES) $(INCLUDES_LIB) -O3

clean:
	$(RM) -R $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean: clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(LIB_FDF)
	$(ECHOC) $(GREEN) "--> $(LIB_FDF) deleted !\n"
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !\n"

re: fclean
	$(ECHOC) $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY: all clean fclean re
.SILENT: $(NAME) $(OBJS) $(LIB_FDF) clean fclean re
