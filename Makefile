# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:43:50 by vharkush          #+#    #+#              #
#    Updated: 2023/06/04 15:07:32 by vharkush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

NAME = so_long

SRCS =	src/so_long.c					\
		src/map_check.c					\
		src/map_check2.c				\
		src/moveit_moveit.c				\
		src/villain.c					\
		src/free.c						\
		src/utils.c						\
		src/utils2.c					\
		get_next_line/get_next_line.c   \
		get_next_line/get_next_line_utils.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz

all:    $(NAME)

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

