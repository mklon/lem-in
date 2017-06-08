#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 12:26:51 by oposhiva          #+#    #+#              #
#    Updated: 2017/03/29 12:26:52 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIB_FILE = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o \
ft_memmove.o ft_memchr.o ft_memcmp.o ft_strlen.o \
ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o \
ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o \
ft_strstr.o ft_strnstr.o ft_strcmp.o ft_strncmp.o \
ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o \
ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o \
ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o \
ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o \
ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
ft_lstiter.o ft_lstmap.o ft_vig_coder.o ft_vig_decoder.o \
ft_strrev.o ft_max_div.o ft_abs.o ft_putnstr.o ft_putnchr.o \
ft_numlen.o ft_power.o ft_putunbr.o ft_numulen.o ft_swap.o

SRC_PRINT = ft_printf.o get_next_line.o qualifier_definition.o \
type_definition.o types/binary.o types/char.o types/integer.o \
types/none.o types/notation.o types/notation_help.o \
types/percent.o types/string.o types/unsigned.o types/wchar.o \
types/wstr.o

CC = gcc

LIB_PATH = ./libft/

SRC_LIB = $(addprefix $(LIB_PATH), $(LIB_FILE))

OBJ = $(SRC_LIB) $(SRC_PRINT)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIB_FILE): %.o: $(LIB_PATH)%.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

$(SRC_PRINT): %.o: %.c
	@$(CC) -c $(FLAGS) -I $(LIB_PATH) $< -o $@

clean:
	rm -f $(OBJ) ft_printf.h.gch $(LIB_PATH)libft.h.gch

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a	

re: fclean all
