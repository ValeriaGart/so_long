/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:45:29 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/09 11:41:36 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	j;
	size_t	lsrc;
	size_t	ldest;

	if (!dest || dest[0] || size == 0)
		return (0);
	j = ft_strlen(dest);
	a = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen((char *)src);
	if (size < 1)
		return (lsrc + size);
	while (src[a] != '\0' && j < size - 1)
	{
		dest[j] = src[a];
		a++;
		j++;
	}
	dest[j] = '\0';
	if (size < ldest)
		return (lsrc + size);
	return (ldest + lsrc);
}
