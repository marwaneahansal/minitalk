/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:16 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/07 08:15:52 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	printf("signale recived ==> %s\n", signal == SIGUSR1 ? "SIGUSER1" : "SIGUSER2");
	
	(void) other;
	(void) info;
}

int main(void)
{
	pid_t				server_pid;
	struct	sigaction	s_sigaction;
	
	server_pid = getpid();
	ft_putstr_fd(1, "Server PID is ==> ");
	ft_putnbr_fd(1, server_pid);
	ft_putchar_fd(1, '\n');

	
	s_sigaction.sa_flags = SA_RESTART;
	s_sigaction.sa_sigaction = signal_handler;
	sigemptyset(&(s_sigaction.sa_mask));
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	pause();
	return (0);
}