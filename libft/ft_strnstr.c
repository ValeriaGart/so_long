/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20ft_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:32:29 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/06 17:33:44 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_while(char *big, size_t len, size_t j, char *little)
{
	int	i;
	int	count;

	while (*big != '\0' && len)
	{
		if (*big == little[0] && len >= j)
		{
			i = 0;
			count = 0;
			while (little[i] != '\0')
			{
				if (big[i] == little[i])
					count++;
				i++;
			}
			if (count == i)
				return ((char *)big);
		}
		big++;
		len--;
	}
	big = NULL;
	return (big);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	char	*res;

	if (little[0] == '\0')
		return ((char *)big);
	j = 0;
	if (!big && len == 0)
		return (0);
	if (ft_strlen((char *)little) > len && big)
		return (NULL);
	while (little[j])
		j++;
	if (ft_strncmp(big, little, j) == 0)
		return ((char *)big);
	res = ft_while((char *)big, len, j, (char *)little);
	if (res != NULL)
		return (res);
	return (NULL);
}
