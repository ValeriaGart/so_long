/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19ft_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:05:51 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/05 18:05:54 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			j;

	j = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (j < n)
	{
		if (str1[j] == str2[j])
			j++;
		else
			return (str1[j] - str2[j]);
	}
	return (0);
}
