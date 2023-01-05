/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahansal <mahansal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:55:42 by mahansal          #+#    #+#             */
/*   Updated: 2023/01/05 04:13:12 by mahansal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "minitalk_utils.h"

typedef struct s_ss {
	size_t	len;
	size_t	recived_signals;
	int		is_sig_reciv;
}	t_ss;

#endif
