/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:52:36 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/08 22:43:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>
#include <stdio.h> // client.c

void	trans_to_binary(int pid, char c)
{
	int	i;
	int temp = 0;

	i = -1;
	while (++i < 8)
	{
		if ((c >> 7) == 0)
		{
			kill(pid, SIGUSR1);
			temp = (temp << 1) + 0;
		}
		else
		{
			kill(pid, SIGUSR2);
			temp = (temp << 1) + 1;
		}
		c = (c << 1) % 0b100000000;
	}
	printf("sending this : %c\n", temp);
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
	//int	i;

	if (ac < 3)
		return (-1);
	//i = -1;
	printf("server PID : %d\n", ft_atoi(av[1]));
	sending_msg(ft_atoi(av[1]), av[2]);
	return (0);
}