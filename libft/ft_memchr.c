/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18ft_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:13:20 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/05 17:13:23 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	ch;

	i = 0;
	res = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (res[i] == ch)
			return (res + i);
		i++;
	}
	return (0);
}
