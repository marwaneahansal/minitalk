# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 02:07:58 by mahansal          #+#    #+#              #
#    Updated: 2022/12/24 20:55:06 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc

NAME			= minitalk

SERVER_NAME		= server

CLIENT_NAME 	= client

SERVER_NAME 	= server

SERVER_SRCS 	= server.c utils/minitalk_utils.c

SERVER_OBJS 	= $(SERVER_SRCS:.c=.o)

CLIENT_SRCS 	= client.c utils/minitalk_utils.c utils/ft_atoi.c

CLIENT_OBJS 	= $(CLIENT_SRCS:.c=.o)

CFLAGS 			= -Wall -Wextra -Werror

all: $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all