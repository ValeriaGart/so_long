/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:49:40 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/13 18:49:44 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_mem(size_t len, unsigned int start, char *s)
{
	size_t	mem;
	size_t	i;
	size_t	j;

	mem = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			mem++;
			j++;
		}
		i++;
	}
	return (mem);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	j = check_mem(len, start, (char *)s);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
