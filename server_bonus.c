/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:16 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/25 02:21:03 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static char c;
	static int 	i;
	
	(void) other;
	if (signal == SIGUSR1)
		c = c | 1;
	else if (signal == SIGUSR2)
		c = c | 0;
	if (i < 7)
		c = c << 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t				server_pid;
	struct	sigaction	s_sigaction;
	
	server_pid = getpid();
	ft_putstr_fd(1, "Server PID is ==> ");
	ft_putnbr_fd(1, server_pid);
	ft_putchar_fd(1, '\n');

	s_sigaction.sa_flags = SA_RESTART | SA_NODEFER;
	s_sigaction.sa_sigaction = signal_handler;
	
	sigemptyset(&(s_sigaction.sa_mask));
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		sleep(1);
	return (0);
}
