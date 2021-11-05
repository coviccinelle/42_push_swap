# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-phng <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 17:09:08 by thi-phng          #+#    #+#              #
#    Updated: 2021/11/05 09:49:32 by thi-phng         ###   ########.fr        #
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


.SILENT:
CRED 	= \033[0;31m
CORANGE	= \033[0;33m
CYELLOW	= \033[1;33m
CGREEN 	= \033[0;32m
CCYAN 	= \033[1;36m
CBLUE 	= \033[0;34m
CPURPLE	= \033[0;35m

all:			TITLE $(NAME)
				printf "${CYELLOW} \n"
				@echo Clumsy Push Swap is on the way!
				printf "${CPURPLE} \n"

TITLE:
	printf "${CRED}  _   ${CORANGE} _     ${CYELLOW}_  ${CGREEN}    ${CCYAN}       ${CBLUE} _     ${CPURPLE}     ${CRED}      \n"
	printf "${CRED} | |_ ${CORANGE}| |_  ${CYELLOW}(_)${CGREEN} ___ ${CCYAN} _ __  ${CBLUE}| |_   ${CPURPLE}_ _  ${CRED} __ _ \n"
	printf "${CRED} |  _|${CORANGE}| ' \\ ${CYELLOW}| |${CGREEN}|___|${CCYAN}| '_ \\ ${CBLUE}| ' \\ ${CPURPLE}| ' \\ ${CRED}/ _\` |\n"
	printf "${CRED}  \__|${CORANGE}|_||_|${CYELLOW}|_|${CGREEN}     ${CCYAN}| .__/ ${CBLUE}|_||_|${CPURPLE}|_||_|${CRED}\\__, |\n"
	printf "${CRED}      ${CORANGE}      ${CYELLOW}   ${CGREEN}     ${CCYAN}|_|     ${CBLUE}     ${CPURPLE}      ${CRED}|___/ \n"
	printf "${CYELLOW} \n"


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

re:				fclean all

.PHONY:			all clean fclean re
