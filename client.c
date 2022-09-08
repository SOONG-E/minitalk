/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:52:36 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/09 00:52:25 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // client.c

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
	if (ac < 3)
		return (-1);
	sending_msg(ft_atoi(av[1]), av[2]);
	return (0);
}