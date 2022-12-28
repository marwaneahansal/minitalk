# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 02:07:58 by mahansal          #+#    #+#              #
#    Updated: 2022/12/28 00:38:09 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc

NAME				= minitalk

SERVER_NAME			= server

CLIENT_NAME 		= client

SERVER_SRCS 		= server.c utils/minitalk_utils.c

SERVER_OBJS 		= $(SERVER_SRCS:.c=.o)

CLIENT_SRCS 		= client.c utils/minitalk_utils.c utils/ft_atoi.c

CLIENT_OBJS 		= $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_NAME	= server_bonus

CLIENT_BONUS_NAME 	= client_bonus

SERVER_BONUS_SRCS 	= server_bonus.c utils/minitalk_utils.c

SERVER_BONUS_OBJS 	= $(SERVER_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS 	= client_bonus.c utils/minitalk_utils.c utils/ft_atoi.c

CLIENT_BONUS_OBJS 	= $(CLIENT_BONUS_SRCS:.c=.o)

CFLAGS 				= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS_NAME)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -f $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -f $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

re: fclean all