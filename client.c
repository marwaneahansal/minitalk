/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:07 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/05 04:02:45 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

void	handle_char(int pid, char c)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	while (i < 8)
	{
		mod = c % 2;
		if (mod)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c / 2;
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
	handle_char(server_pid, '\n');
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd(2, "Program take 2 arguments (Server PID and message)!\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd(2, "Server PID is wrong !");
		exit(1);
	}
	send_msg(server_pid, argv[2]);
	return (0);
}
