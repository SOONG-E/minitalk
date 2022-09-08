/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:01 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/08 20:33:37 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_put_rec(long c, int fd)
{
	if (c >= 10)
	{
		ft_put_rec(c / 10, fd);
		c = c % 10;
	}
	ft_putchar(c + '0', fd);
}

void	ft_putnbr(int n, int fd)
{
	long	num;

	if (fd >= 0)
	{
		num = n;
		if (n < 0)
		{
			write(fd, "-", 1);
			num = num * (-1);
		}
		ft_put_rec(num, fd);
	}
}
