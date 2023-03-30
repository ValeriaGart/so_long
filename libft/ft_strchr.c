/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:23:29 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/05 11:26:39 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (res + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (res + i);
	return (NULL);
}
