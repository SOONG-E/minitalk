/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:26:49 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/08 23:21:08 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "server.h"
#include <stdio.h> //server.c

t_box	res;

void	catching_sig(int sig)
{
	printf("\n%d", sig);
	if (sig == SIGUSR1)
	{
		res.sum = (res.sum << 1) + 0;
		++(res.phase);
		//printf(" 0");
	}
	else
	{
		res.sum = (res.sum << 1) + 1;
		res.sum += 1;
		++(res.phase);
		//printf(" 1");
	}
	if (res.phase == 8)
	{
		res.phase = 0;
		//printf("%c", res.sum);
		res.sum = 0;
	}
	printf("\n%d", res.phase);
}

void	waiting_msg(void)
{
	(void)signal(SIGUSR1, catching_sig);
	(void)signal(SIGUSR2, catching_sig);
	while (pause() == -1)
	{
		
	}
}

int	main()
{
	ft_putnbr(getpid(), 1);
	waiting_msg();
	return (0);
}
