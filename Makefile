# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 17:09:08 by thi-phng          #+#    #+#              #
#    Updated: 2021/10/30 16:14:54 by thi-phng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

CC			=	clang

SRCS		=	push_swap.c \
				parsing.c \
				utils.c \




OBJS		=	$(SRCS:.c=.o)

%.o : %.c
				$(CC) -c $(CFLAGS) -o $@ $<

all:			$(NAME)

$(NAME) :		$(OBJS)
						$(CC) $(CLAGS) $(OBJS) -o $(NAME)

test:
				$(CC) $(CFLAGS) push_swap.c && ./a.out

clean:
				$(RM) $(OBJS)

fclean:			clean
						$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
