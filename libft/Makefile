# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 21:17:54 by ynguyen           #+#    #+#              #
#    Updated: 2024/01/06 20:39:28 by vharkush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES	=		ft_isalpha.c	\
			ft_atol.c		\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_isspace.c	\
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
			ft_itoa.c	\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_split.c	

BONUS	=	ft_lstnew.c	\
			ft_lstadd_front.c	\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c	\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c
#			ft_lstmap.c	

NAME	=		libft.a
OBJECTS	=		$(SOURCES:.c=.o)
BONUS_OBJS	=	$(BONUS:.c=.o)
RM	=		rm -f
CFLAGS	=		-g -Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJECTS)
			ar rcs	$(NAME)	$(OBJECTS)

$(OBJECTS):		$(SOURCES) 
			cc -c $(CFLAGS) $(SOURCES)		
clean:
			$(RM)	$(OBJECTS)	$(BONUS_OBJS)

fclean:			clean
			$(RM)	$(NAME)

re:			fclean	$(NAME)

bonus:		$(BONUS_OBJS)
			cc -c $(CFLAGS) $(BONUS)
			ar rcs	$(NAME)	$(BONUS_OBJS)
			
.PHONY:			all clean fclean re bonus
