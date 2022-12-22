/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:16 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/22 05:27:17 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static char c;
	static int i;
	// 00000000
	// 01100001

	if (signal == SIGUSR1)
	{
		// ft_putchar_fd(1, '1');
		c = c | 1;
		// kill(info->si_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)
	{
		// ft_putchar_fd(1, '0');
		c = c | 0;
		// kill(info->si_pid, SIGUSR1);
	}
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
	
	(void) other;
	(void) info;
}

int main(void)
{
	pid_t				server_pid;
	struct	sigaction	s_sigaction;
	
	server_pid = getpid();
	ft_putstr_fd(1, "\033[1;32mServer PID is \033[0;0m==> ");
	ft_putnbr_fd(1, server_pid);
	ft_putchar_fd(1, '\n');

	s_sigaction.sa_flags = SA_NODEFER;
	s_sigaction.sa_sigaction = signal_handler;
	
	sigemptyset(&(s_sigaction.sa_mask));
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);

	// signal(SIGUSR1, test);
	// signal(SIGUSR2, test);


	
	while (1)
		sleep(1);
	return (0);
}