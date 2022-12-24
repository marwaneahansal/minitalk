/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:07 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/24 20:54:26 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/client.h"
#include <stdio.h>
#include <string.h>

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

typedef struct s_ss {
	int len;
	int recived_signals;
} t_ss;

t_ss *st;


void	signal_handler()
{
	st->recived_signals++;
	if (st->recived_signals == st->len * 8)
	{
		ft_putstr_fd(1, "\n Message sent successfully\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	pid_t				server_pid;
	struct	sigaction	s_sigaction;
	
	st = malloc(sizeof(t_ss));
	st->recived_signals = 0;
	st->len = 0;                                                                                                                             
	if (argc != 3)
	{
		ft_putstr_fd(2, "Program takes at least 2 arguments (Server PID and the message)!\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd(2, "Server PID is wrong !");
		exit(1);
	}
	s_sigaction.sa_flags = SA_NODEFER;
	s_sigaction.sa_sigaction = signal_handler;
	sigemptyset(&(s_sigaction.sa_mask));
	sigaction(SIGUSR1, &s_sigaction, 0);
	st->len = strlen(argv[2]);
	send_msg(server_pid, argv[2]);
	while (1)
		sleep(1);
	return (0);
}
