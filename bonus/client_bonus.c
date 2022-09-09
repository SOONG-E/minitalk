/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:52:36 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/09 22:31:08 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	receive_ans(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1)
	{
		write(1, "PID : ", 7);
		ft_putnbr(info->si_pid, 1);
		write(1, " success sending\n", 18);
	}
}

void	trans_to_binary(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(1000);
	}
}

void	sending_msg(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		trans_to_binary(pid, str[i]);
	trans_to_binary(pid, 0);
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	if (ac < 3)
		return (-1);
	act.sa_sigaction = receive_ans;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sending_msg(ft_atoi(av[1]), av[2]);
	return (0);
}