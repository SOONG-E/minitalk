/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:18:34 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/11 15:22:06 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long	idx;
	long long	ret;
	int			s;

	idx = 0;
	ret = 0;
	s = 1;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			s = -1;
		idx++;
	}
	while (48 <= str[idx] && str[idx] <= 57)
	{
		ret = ret * 10 + (str[idx] - 48);
		idx++;
	}
	return ((int)(s * ret));
}
