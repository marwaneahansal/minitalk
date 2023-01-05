/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:55:12 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/05 04:28:40 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"

t_ss	g_st;

void	handle_char(int pid, unsigned char c)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	while (i < 8)
	{
		if (!g_st.is_sig_reciv)
			pause();
		mod = c % 2;
		if (mod)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		c = c / 2;
		g_st.is_sig_reciv = 0;
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

void	send_pid(pid_t server_pid, char *msg)
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

void	signal_handler(int signal)
{
	(void) signal;
	g_st.is_sig_reciv = 1;
	g_st.recived_signals++;
	if (g_st.recived_signals == g_st.len * 8)
	{
		ft_putstr_fd(1, "\n Message sent successfully\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

	g_st.recived_signals = 0;
	g_st.len = 0;
	g_st.is_sig_reciv = 1;
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
	signal(SIGUSR1, signal_handler);
	g_st.len = ft_strlen(argv[2]) + 2;
	send_msg(server_pid, argv[2]);
	while (1)
		sleep(1);
	return (0);
}
