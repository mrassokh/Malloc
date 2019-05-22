# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 10:55:05 by mrassokh          #+#    #+#              #
#    Updated: 2017/05/12 18:00:34 by elyahove         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -g
SRC = 	ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_isdigit.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_atoi.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_strlen.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_swap.c\
		ft_min_array.c\
		ft_bulb_sort.c\
		ft_choose_sort.c\
		ft_merge_sort.c\
		ft_listpushback.c\
		get_next_line.c\
		matrix_mult.c\
		matrix_mult_a.c\
		orto_zy.c\
		orto_xy.c\
		orto_xz.c\
		rotate_x.c\
		rotate_y.c\
		rotate_z.c\
		create_single_m.c\
		create_masht_m.c\
		create_shift_m.c\
		rotate_x_a.c\
		rotate_y_a.c\
		rotate_z_a.c\
		create_single_m_a.c\
		create_masht_m_a.c\
		create_shift_m_a.c\
		matrix_clear.c\
		create_t_matr.c\
		ft_atof.c \
		product_vector_float.c \
		vector_set.c \
		vectors_add.c \
		vectors_minus.c \
		dot_product.c \
		vector_abs.c \
		product_vector_float.c \
		vector_product.c \
		matrix.c \
		quaternions.c \
		ft_str_strsplit.c \
		ft_strsplit_with_empty.c \
		ft_double_array_memdel.c \
		ft_strrev.c


BIN = $(subst .c,.o,$(SRC))
NAME = libft.a
INC = ./includes/

all: $(NAME)
		ar rc $(NAME) $(BIN)
		ranlib $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRC) -I$(INC)

clean:
		rm -f $(BIN)

fclean: clean
		rm -f $(NAME)

re: fclean all
