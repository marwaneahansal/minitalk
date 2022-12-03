# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 02:07:58 by mahansal          #+#    #+#              #
#    Updated: 2022/12/03 11:53:40 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc

NAME			= minitalk.a

SERVER_NAME		= server

CLIENT_NAME 	= client

SERVER_NAME 	= server

SERVER_SRCS 	= server.c minitalk_utils.c

SERVER_OBJS 	= $(SERVER_SRCS:.c=.o)

CFLAGS 			= -Wall -Wextra -Werror

all: $(NAME)

# %.o: %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all