# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgerdes <tgerdes@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 14:42:49 by tgerdes           #+#    #+#              #
#    Updated: 2021/12/20 02:10:15 by tgerdes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_HELPER = helpers.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_HELPER = ${SRC_HELPER:.c=.o}

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_HELPER_BONUS = helpers_bonus.c

OBJ_SERVER_BONUS	= ${SRC_SERVER_BONUS:.c=.o}
OBJ_CLIENT_BONUS	= ${SRC_CLIENT_BONUS:.c=.o}
OBJ_HELPER_BONUS	= ${SRC_HELPER_BONUS:.c=.o}

CC			= gcc

RM			= rm -fr

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME_SERVER} ${NAME_CLIENT}

$(NAME_SERVER): ${OBJ_SERVER} ${OBJ_HELPER}
		${CC} -o ${NAME_SERVER} ${OBJ_SERVER} ${OBJ_HELPER}

$(NAME_CLIENT): ${OBJ_CLIENT} ${OBJ_HELPER}
		${CC} -o ${NAME_CLIENT} ${OBJ_CLIENT} ${OBJ_HELPER}

bonus: ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

$(NAME_SERVER_BONUS): ${OBJ_SERVER_BONUS} ${OBJ_HELPER_BONUS}
		${CC} -o ${NAME_SERVER_BONUS} ${OBJ_SERVER_BONUS} ${OBJ_HELPER_BONUS}

$(NAME_CLIENT_BONUS): ${OBJ_CLIENT_BONUS} ${OBJ_HELPER_BONUS}
		${CC} -o ${NAME_CLIENT_BONUS} ${OBJ_CLIENT_BONUS} ${OBJ_HELPER_BONUS}

clean:
		${RM} ${OBJ_SERVER} ${OBJ_CLIENT} ${OBJ_HELPER} ${OBJ_SERVER_BONUS} ${OBJ_CLIENT_BONUS} ${OBJ_HELPER_BONUS}

fclean: clean
		${RM} ${NAME_SERVER} ${NAME_CLIENT} ${NAME_SERVER_BONUS} ${NAME_CLIENT_BONUS}

re:		fclean all