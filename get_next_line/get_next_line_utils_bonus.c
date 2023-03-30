/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:24:17 by vharkush          #+#    #+#             */
/*   Updated: 2022/11/10 20:24:23 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_int_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (-1);
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == 0 && dest == 0)
		return (0);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src++);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		ls1;
	int		ls2;
	int		i;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	i = ls1 + ls2;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1, s2, ls2);
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	c;

	c = 0;
	b = size - 1;
	a = 0;
	while (src[a])
		a++;
	if (size < 1)
		return (a);
	while (c < b && src[c] != '\0')
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (a);
}
