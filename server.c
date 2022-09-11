/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/11 15:21:20 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "server.h"

t_box	g_res;

void	catching_sig(int signo)
{
	if (signo == SIGUSR1)
		g_res.sum |= 0;
	else
		g_res.sum |= 1;
	++(g_res.phase);
	if (g_res.phase == 8)
	{
		write(1, &(g_res.sum), 1);
		g_res.phase = 0;
		g_res.sum = 0;
	}
	g_res.sum <<= 1;
}

void	waiting_msg(void)
{
	(void)signal(SIGUSR1, catching_sig);
	(void)signal(SIGUSR2, catching_sig);
	while (1)
		pause();
}

int	main(void)
{
	write(1, "server's PID : ", 16);
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	waiting_msg();
	return (0);
}
