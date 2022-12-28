/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:55:42 by mahansal          #+#    #+#             */
/*   Updated: 2022/12/27 23:54:09 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "minitalk_utils.h"

typedef struct s_ss {
	size_t len;
	size_t recived_signals;
} t_ss;

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#endif
