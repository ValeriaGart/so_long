# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharkush <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 11:44:03 by vharkush          #+#    #+#              #
#    Updated: 2022/10/17 16:50:12 by vharkush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c	\
		ft_memset.c	\
		ft_bzero.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_strnstr.c	\
		ft_atoi.c	\
		ft_calloc.c	\
		ft_strdup.c	\
		ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c	\
		ft_itoa.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c

BONUS	=	ft_lstnew.c	\
		ft_lstadd_front.c	\
		ft_lstsize.c	\
		ft_lstlast.c	\
		ft_lstadd_back.c	\
		ft_lstdelone.c	\
		ft_lstclear.c	\
		ft_lstiter.c	\
		ft_lstmap.c

OBJ     =       ${SRC:.c=.o}

B_OBJS  =       ${BONUS:.c=.o}

CC      =       cc

CFLAGS  =       -Wextra -Werror -Wall

NAME    =       libft.a

RM	=	rm -f

AR	=	ar rc

all:    ${NAME}

$(NAME):	${OBJ}
			${AR} ${NAME} ${OBJ}
			ranlib ${NAME}

bonus:		${B_OBJS}
			${AR} ${NAME} ${B_OBJS}
			ranlib ${NAME}

clean:
		${RM} ${OBJ} ${B_OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY:	all bonus clean fclean re
