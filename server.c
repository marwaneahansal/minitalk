/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:16 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/05 04:00:10 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

void	signal_handler(int signal)
{
	static int	c;
	static int	i;
	static int	x;

	if (i == 0)
		x = 1;
	if (signal == SIGUSR1)
		c += x * 1;
	x *= 2;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				server_pid;

	server_pid = getpid();
	ft_putstr_fd(1, "Server PID is ==> ");
	ft_putnbr_fd(1, server_pid);
	ft_putchar_fd(1, '\n');
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
	return (0);
}
