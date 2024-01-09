/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:39:45 by ynguyen           #+#    #+#             */
/*   Updated: 2022/10/24 15:56:01 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;
	size_t				i;

	s1 = (unsigned char *)dest;
	s2 = (unsigned const char *)src;
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (s2 < s1)
	{
		while (i++ < n)
			s1[n - i] = s2[n - i];
	}
	else
	{
		while (n-- > 0)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}
