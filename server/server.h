/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:48 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/08 21:51:00 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef struct s_box
{
	int	sum;
	int	phase;
}	t_box;

void	ft_putnbr(int n, int fd);
int		ft_strlen(char *str);

#endif