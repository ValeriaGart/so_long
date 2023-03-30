/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:56:06 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/07 09:56:09 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;
	size_t	i;

	a = malloc(nmemb * size);
	if (a == 0)
		return (0);
	i = nmemb * size;
	while (i--)
		a[i] = '\0';
	return (a);
}
