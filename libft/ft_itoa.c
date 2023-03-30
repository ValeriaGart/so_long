/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:28:25 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/11 17:28:28 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

void	ft_putnum(size_t n, int *i, char *c)
{
	if (n <= 9)
	{
		c[(*i)++] = n + '0';
	}
	else
	{
		ft_putnum(n / 10, i, c);
		ft_putnum(n % 10, i, c);
	}
}

char	*ft_min(int num)
{
	char	*c;
	int		i;

	i = num + 2147483650;
	c = malloc(sizeof(char) * 12);
	if (!c)
		return (0);
	c[0] = '-';
	c[1] = '2';
	ft_putnum(147483648, &i, c);
	c[i] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		i;
	long	num;

	num = n;
	if (num == -2147483648)
	{
		c = ft_min(num);
		return (c);
	}
	i = ft_check_len(num);
	c = malloc(sizeof(char) * (i + 1));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (num < 0)
	{
		c[i++] = '-';
		num *= -1;
	}
	ft_putnum(num, &i, c);
	c[i] = '\0';
	return (c);
}
