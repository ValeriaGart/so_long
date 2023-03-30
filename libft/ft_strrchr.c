/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16ft_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:04:39 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/05 15:06:28 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*l;
	char	*res;

	i = 0;
	l = 0;
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (char)c)
			l = res + i;
		i++;
	}
	if ((char)c == '\0')
		return (res + i);
	return (l);
}
