/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:02:37 by ynguyen           #+#    #+#             */
/*   Updated: 2022/10/26 10:33:22 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null(long int num)
{
	char	*str;

	if (num == 0)
	{
		str = ft_calloc(1, 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	return (NULL);
}

static unsigned int	ft_digitcount(long int num)
{
	unsigned int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		num;
	long int		single;
	unsigned int	i;

	num = n;
	i = ft_digitcount(num);
	if (num == 0)
		return (ft_null(num));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		single = num;
		str[i--] = single % 10 + 48;
		num /= 10;
	}
	return (str);
}
