# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/12 09:31:31 by mrassokh          #+#    #+#              #
#    Updated: 2017/06/03 14:38:10 by mrassokh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME_HOST_TYPE = libft_malloc_$(HOSTTYPE).so
NAME = libft_malloc.so

#[----------------------------------HEADERS-----------------------------------]#

HEADERS_PATH =    ./includes/
LIBFTINC = $(LIBFTPATH)/includes
LIBSINC = -I./$(LIBFTINC)

INC =-I$(HEADERS_PATH) $(LIBSINC)

#[---------------------------------LIBRARIES----------------------------------]#
LIBPATH = ./
LIBFTPATH = $(LIBPATH)libft
LIBFT = -lft
LIBS = -L. $(LIBFT)

#[--------------------------------COMPILATION---------------------------------]#

CC = gcc
FLAGS    = -Wall -Wextra -Werror
LIB_FLAG = -shared -fPIC


#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH     = src

ROOT = malloc.c

FUNCTIONS = memory_block.c ft_itoa_base.c
#ft_strnew.c

SRC = $(ROOT) $(FUNCTIONS)
OBJ=$(SRC:%.c=%.o)

#[-----------------------------------COLORS-----------------------------------]#

GREEN                   =       \033[32m
RESET                   =       \033[39m
YELLOW                  =       \033[33m
RED                     =       \033[31m

#[------------------------------------MAKE------------------------------------]#

vpath %.c $(SRC_PATH)
vpath %.h $(HEADERS_PATH)


all: $(NAME)

$(NAME): make_libs $(OBJ)
	$(CC) $(FLAGS) $(LIB_FLAG) -o $(NAME_HOST_TYPE) $(OBJ) $(INC) $(LIBS); \
	rm -f $(OBJ); \
	rm -f $(NAME); \
	ln -s $(NAME_HOST_TYPE) $(NAME); \
	echo "$(GREEN)[$(NAME) compiled]$(GREEN)"; \

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@  $(INC) -g ;

make_libs: cc_libft

cc_libft:
	@	if [ -a libft.a ]; \
			then echo "$(GREEN)[libft already compiled]$(GREEN)"; \
		else \
			cd $(LIBFTPATH);\
			make;\
			make clean;\
			mv libft.a ../;\
			echo "$(GREEN)[libft compiled]$(GREEN)"; \
		fi;

clean:
	@ rm -f $(OBJ)
	@ rm -f $(LIBPATH)libft.a
	@ echo "$(YELLOW)[clean obj]$(RESET)"

fclean: clean
	@ rm -f $(NAME_HOST_TYPE)
	@ rm -f $(NAME)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
