/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/09 22:22:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "server_bonus.h"

t_box	res;

void	catching_sig(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (signo == SIGUSR1)
		res.sum |= 0;
	else
		res.sum |= 1;
	++(res.phase);
	if (res.phase == 8)
	{
		write(1, &(res.sum), 1);
		if (!(res.sum))
			kill(info->si_pid, SIGUSR1);
		res.phase = 0;
		res.sum = 0;
	}
	res.sum <<= 1;
}

int	main()
{
	struct sigaction	act;

	act.sa_sigaction = catching_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	write(1, "server's PID : ", 16);
	ft_putnbr(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
