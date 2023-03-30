/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:54:55 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/06 18:56:51 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_do(char *str, int i, int sign)
{
	unsigned long	j;
	unsigned long	lim;
	int				n;

	j = 0;
	n = 0;
	lim = (unsigned long)(4294967295 / 10);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		n = str[i] - '0';
		if (sign == 1 && (j > lim || (j == lim && n > 7)))
			return (-1);
		if (sign == -1 && (j > lim || (j == lim && n > 8)))
			return (0);
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	j;
	int	i;

	i = 0;
	sign = 1;
	if (str == ft_itoa(-2147483648))
	{
		i = -2147483648;
		return (i);
	}
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	j = ft_do((char *)str, i, sign);
	return (sign * j);
}
