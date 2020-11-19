# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 17:11:32 by ninieddu          #+#    #+#              #
#    Updated: 2020/11/19 15:58:30 by ninieddu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


SRC			=	./srcs_s/ft_strlen.s ./srcs_s/ft_strcpy.s ./srcs_s/ft_write.s \
				./srcs_s/ft_read.s ./srcs_s/ft_strcmp.s ./srcs_s/ft_strdup.s

OBJ			=	$(SRC:.s=.o)

NAME		=	libasm.a

HEADER		=	libasm.h

CC			=	nasm

FLAGS		=	-felf64 

RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o: %.s $(HEADER)
	$(CC) $(FLAGS) $< -o $@

test:
	touch test.txt | echo -n "0123456789" > test.txt 
	gcc -Wall -Werror -Wextra -no-pie -o test main.c libasm.a

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} test.txt test
	
re: fclean all

.PHONY: test