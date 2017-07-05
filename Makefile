#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/22 16:31:48 by oposhiva          #+#    #+#              #
#    Updated: 2017/06/22 16:31:49 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

CC = gcc

LIBFT = printflibft/libftprintf.a

SRC = src/assistance.c src/error.c src/handle.c src/motion.c src/race.c\
src/validation.c src/directions.c src/generate.c src/main.c

OBJ = $(SRC:.c=.o)

HEADERS = lem_in.h printflibft/get_next_line.h printflibft/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C printflibft/

libft_clean:
	make -C printflibft/ clean

libft_fclean:
	make -C printflibft/ fclean

clean: libft_clean
	rm -f $(OBJ) lem_in.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
