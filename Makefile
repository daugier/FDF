# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/24 23:04:21 by daugier           #+#    #+#              #
#    Updated: 2016/05/27 14:39:35 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

RM	= rm -f

LIB = libft/libft.a

HEADER = fdf.h

CC = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = 	fdf.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/ 
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
