# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 12:23:32 by thi-phng          #+#    #+#              #
#    Updated: 2021/02/01 10:46:08 by thi-phng         ###   ########.fr        #
#                                                                              #
# *****************************************************************************#

NAME		= 	libft.a

CFLAGS  	= 	-Wall -Wextra -Werror

RM			=	rm -rf

CC			= 	gcc

SRCDIR		=	ft_substr.c \
			ft_strlen.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
	   		ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memccpy.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \

OBJS		= $(SRCDIR:.c=.o)

BONUS		= ft_lstnew.c \
		  	ft_lstadd_front.c \
			ft_lstsize.c \
		 	ft_lstlast.c \
		 	ft_lstadd_back.c \
		 	ft_lstdelone.c \
		  	ft_lstclear.c \
		 	ft_lstiter.c \
		  	ft_lstmap.c \

BONUS_OBJS	= $(BONUS:.c=.o)

%.o : %.c
			$(CC) $(CFLAGS) -c $<
		
all: 		$(NAME)

$(NAME)	: 	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) *.o

fclean: 	clean
	$(RM) $(NAME)

re: 	fclean $(NAME)

bonus:	$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
