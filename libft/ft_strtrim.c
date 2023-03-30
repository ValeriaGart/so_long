/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:24:06 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/09 15:24:10 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkpls(char *set, char a)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*trimpls(char *s1, char *set, int *j, int i)
{
	int		n;
	int		i1;
	int		len;
	char	*str;

	i1 = 0;
	len = ft_strlen(s1);
	while (checkpls(set, s1[len - i1 - 1]) > 0)
		i1++;
	n = len - (i1 + i);
	str = (char *)malloc(sizeof(*s1) * (n + 1));
	if (!str)
		return (NULL);
	while (*j < n)
	{
		str[*j] = s1[i + *j];
		*j += 1;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	j = len;
	while (checkpls((char *)set, s1[i]) > 0)
		i++;
	j = 0;
	if (i == len)
		str = malloc(1);
	else
		str = trimpls((char *)s1, (char *)set, &j, i);
	if (str)
		str[j] = '\0';
	return (str);
}
