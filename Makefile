# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauvray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/17 11:01:12 by tauvray           #+#    #+#              #
#*   Updated: 2014/11/21 15:01:43 by tauvray          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# *********************************VARIABLES***********************************#

NAME = fdf

SRC_DIR = srcs/

SRC = srcs/main.c \
	  srcs/errors.c \
	  srcs/draw.c \
	  srcs/segment.c \
	  srcs/key_hook.c \
	  srcs/img_put.c \
	  srcs/get_pos.c \
	  srcs/tab.c

INC = includes/

LIBINC = libft/includes/

LIB = libft.a

BIN_DIR = bin/

BIN = main.o \
	  errors.o \
	  draw.o \
	  segment.o \
	  key_hook.o \
	  img_put.o \
	  get_pos.o \
	  tab.o

CC = gcc

OPTS = -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -g

# *********************************RULES***************************************#

all			:  $(NAME)

$(NAME)		: 
	make -C libft/
	$(CC) $(OPTS) -I $(LIBINC) -I includes/ -c $(SRC)
	$(CC) $(OPTS) $(BIN) -L libft/ -lft -o $(NAME)


clean 		:
	make -C libft/ clean
	rm -f $(BIN)

fclean		: clean
	make -C libft/ fclean
	rm -f $(NAME)

re			: fclean all 
