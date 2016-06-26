# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/24 23:04:21 by daugier           #+#    #+#              #
#    Updated: 2016/06/27 01:07:02 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM	= rm -f

LIB = -I ./libft/include -L ./libft/ -lft

HEADER = -I ./include

CC = gcc -Wall -Wextra -Werror -I./include

MLX = -lmlx -framework OpenGL -framework AppKit 

SRCS = 	srcs/fdf.c \
		srcs/stock_map.c \
		srcs/main.c \
		srcs/bresenham.c \
		srcs/windows_param.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(MLX) -o $(NAME) $(OBJS) $(LIB) $(HEADER)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
