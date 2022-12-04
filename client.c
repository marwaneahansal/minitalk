/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 02:08:07 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/04 03:29:36 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd(2, "Arguments are not enough!!\n");
		exit(0);
	}
	kill(atoi(argv[1]), 2);
	return (0);
}