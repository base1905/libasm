# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arannara <base1905@yandex.ru>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 11:56:30 by arannara          #+#    #+#              #
#    Updated: 2020/11/10 11:56:38 by arannara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBB = $(SRCS:%.s=%.o)

all: $(NAME)

$(NAME): $(OBB)
	ar rc $(NAME) $(OBB)
	ranlib $(NAME)

%.o: %.s
	nasm -f macho64 $<

clean:
	rm -rf $(OBB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc main.c -I /. -L. -lasm
	./a.out < Makefile