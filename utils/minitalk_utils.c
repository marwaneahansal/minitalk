/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:38:01 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/05 04:08:51 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_utils.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(int fd, char *str)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar_fd(fd, *str);
			str++;
		}
	}	
}

void	ft_putnbr_fd(int fd, int n)
{
	if (n == -2147483648)
		ft_putstr_fd(fd, "-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(fd, '-');
			n *= -1;
		}
		if (n < 10)
		{
			ft_putchar_fd(fd, n + '0');
		}
		else
		{
			ft_putnbr_fd(fd, n / 10);
			ft_putchar_fd(fd, n % 10 + '0');
		}
	}
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
