/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:02:27 by ynguyen           #+#    #+#             */
/*   Updated: 2022/10/24 15:59:52 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start(char const *str, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != str[i])
		{
			if (set[j] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static unsigned int	ft_end(char const *str, char const *set)
{
	unsigned int	a;
	unsigned int	b;

	a = ft_strlen(str);
	while (a > 0)
	{
		b = 0;
		while (str[a] != set[b])
		{
			if (set[b] == '\0' && set[b] != str[a])
				return (a);
			b++;
		}
		a--;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*str;

	start = ft_start(s1, set);
	end = ft_end(s1, set);
	end = end + 1 - start;
	str = ft_substr(s1, start, end);
	return (str);
}
