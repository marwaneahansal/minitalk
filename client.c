/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:07 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/13 16:35:31 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>

void handle_char(int pid, char c)
{
    int i;
    unsigned char mask;

    i = 0;
    mask = 0b10000000;
    while (i < 8)
    {
        if (mask & c)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        mask = mask >> 1;
				usleep(100);
    }
}

void	send_msg(pid_t server_pid, char *msg)
{
	int		i;

	i = 0;
	while (msg[i])
	{
		handle_char(server_pid, msg[i]);
		i++;
	}
	handle_char(server_pid, msg[i]);
}

int main(int argc, char *argv[])
{
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_putstr_fd(2, "Program takes at least 2 arguments (Server PID and the message)!\n");
		exit(1);
	}
	//*****************
	//** use ft_atoi **
	//*****************
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
		ft_putstr_fd(2, "Server PID is wrong!\n");
	send_msg(server_pid, argv[2]);
	// pause();
	return (0);
}