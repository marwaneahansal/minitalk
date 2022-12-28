/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:39:38 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/27 23:55:42 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	ft_putchar_fd(int fd, char c);
void	ft_putstr_fd(int fd, char *str);
void	ft_putnbr_fd(int fd, int n);
int		ft_atoi(char *str);
size_t	ft_strlen(char *str);

#endif