/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:07 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/07 08:11:01 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdio.h>

void	send_msg(pid_t server_pid, char *msg)
{
	kill(server_pid, SIGUSR2);
	printf("msg to be sent: %s\n", msg);
}

int main(int argc, char *argv[])
{
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_putstr_fd(2, "Programs takes only 2 arguments (Server PID and the message)!\n");
		exit(1);
	}
	//
	// use ft_atoi
	//
	server_pid = atoi(argv[1]);
	if (server_pid <= 0)
		ft_putstr_fd(2, "Server PID is wrong!\n");
	send_msg(server_pid, argv[2]);
	// pause();
	return (0);
}