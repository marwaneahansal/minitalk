# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 02:07:58 by mahansal          #+#    #+#              #
#    Updated: 2022/12/03 02:08:04 by mahansal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc

NAME			= minitalk.a

CLIENT_NAME 	= client

SERVER_NAME 	= server

SRCS 			= 

OBJS 			= $(SRCS:.c=.o)

CFLAGS 			= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all