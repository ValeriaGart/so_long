/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:58:37 by vharkush          #+#    #+#             */
/*   Updated: 2022/09/12 16:00:00 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			j;

	if (!s1 || !s2 || n == 0)
		return (1);
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	j = 0;
	if (n == 0)
		return (0);
	while ((j < n - 1) && st1[j] != '\0' && st1[j] == st2[j])
		j++;
	return (st1[j] - st2[j]);
}
