/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:52:42 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/09 14:53:02 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		ls1;
	int		ls2;
	int		i;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	i = ls1 + ls2;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1, s2, ls2);
	str[i] = '\0';
	return (str);
}
