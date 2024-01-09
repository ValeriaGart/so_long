/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:25:26 by ynguyen           #+#    #+#             */
/*   Updated: 2023/10/27 16:57:15 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordcount(char const *s, char c)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] && s[index] != c)
			count++;
		while (s[index] != c && s[index])
			index++;
	}
	return (count);
}

static unsigned int	ft_start(char const *s, char c)
{
	unsigned int	start;

	start = 0;
	while (s[start])
	{
		if (s[start] != c)
			return (start);
		start++;
	}
	return (0);
}

static unsigned int	ft_len(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			return (len);
		len++;
	}
	return (len);
}

static void	*ft_free(char **new, unsigned int index)
{
	while (index--)
		free(new[index]);
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	size;
	char			**new;
	unsigned int	index;
	unsigned int	start;
	unsigned int	len;

	start = 0;
	len = 0;
	index = 0;
	size = ft_wordcount(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	while (index < size)
	{
		start += len + ft_start(&s[start + len], c);
		len = ft_len(&s[start], c);
		new[index] = ft_substr(s, start, len);
		if (!new[index])
			return (ft_free(new, index));
		index++;
	}
	new[index] = (char *)0;
	return (new);
}
