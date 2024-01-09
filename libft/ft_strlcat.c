/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:56:53 by ynguyen           #+#    #+#             */
/*   Updated: 2022/10/21 14:15:41 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	size_t		i;
	size_t		slen;
	size_t		dlen;

	if (!dst && !src)
		return (0);
	s = (char *)src;
	i = 0;
	slen = ft_strlen(s);
	dlen = ft_strlen(dst);
	if (size == 0)
		return (slen);
	if (size < dlen)
		return (size + slen);
	if (!dst)
		return (slen);
	while (src[i] && (dlen + i) < size - 1)
	{
		dst[dlen + i] = s[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (slen + dlen);
}
