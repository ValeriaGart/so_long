# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:43:50 by vharkush          #+#    #+#              #
#    Updated: 2023/06/08 21:14:14 by vharkush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

NAME = so_long

SRCS =	src/so_long.c					\
		src/map_check.c					\
		src/map_check2.c				\
		src/moveit_moveit.c				\
		src/free.c						\
		src/utils.c						\
		src/utils2.c

LINE = get_next_line/get_next_line.c   \
		get_next_line/get_next_line_utils.c

SRCSB = src/so_long_bonus.c						\
		src/map_check_bonus.c					\
		src/map_check2_bonus.c				\
		src/moveit_moveit_bonus.c				\
		src/villain_bonus.c					\
		src/free_bonus.c						\
		src/utils_bonus.c						\
		src/utils2_bonus.c

CC = cc

CFLAGS = -g -Wextra -Werror -Wall

INCL = -I ./incl

OBJS = $(SRCS:.c=.o)

OLINE = $(LINE:.c=.o)

OBJSB = $(SRCSB:.c=.o)

$(NAME): $(OBJS) $(OLINE)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(OLINE) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz

all:    $(NAME)	

bonus: $(OBJSB) $(OLINE)
		$(MAKE) -C ./libft
		$(MAKE) -C ./minilibx-linux
		$(CC) -o so_long_bonus $(CFLAGS) $(OBJSB) $(OLINE) $(LIBFT) $(MLX) -lX11 -lXext -lm -lz

clean:
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./minilibx-linux
		rm -rf $(OBJS)
		rm -rf $(OBJSB)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)
		rm -rf $(bonus)
		rm -rf so_long_bonus

re: fclean all

.PHONY: all clean fclean re

