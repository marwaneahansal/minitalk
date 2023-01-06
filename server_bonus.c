/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:16 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/06 03:45:03 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/server.h"

int	g_is_sig_recive;

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static int	c;
	static int	i;
	static int	pow;

	if (i == 0)
		pow = 1;
	if (signal == SIGUSR1)
		c += pow;
	pow *= 2;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	if (kill(info->si_pid, SIGUSR1))
		ft_show_error("Failed to send a signal\n");
	(void) other;
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	s_sigaction;

	server_pid = getpid();
	ft_putstr_fd(1, "Server PID is ==> ");
	ft_putnbr_fd(1, server_pid);
	ft_putchar_fd(1, '\n');
	s_sigaction.sa_flags = 0;
	s_sigaction.sa_sigaction = signal_handler;
	sigemptyset(&(s_sigaction.sa_mask));
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		sleep(1);
	return (0);
}
