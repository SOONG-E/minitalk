/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:30:48 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/11 19:29:09 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# define WAIT	0
# define READY	1

typedef struct s_box
{
	int		sum;
	int		phase;
	char	*str;
	int		len;
	int		client_pid;
}	t_box;

void	ft_putnbr(int n, int fd);
void	get_client_pid(int signo, siginfo_t *info, void *context);
void	catching_sig(int signo, siginfo_t *info, void *context);

#endif