/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23ft_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:07:23 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/06 19:07:56 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret_str;

	i = 1;
	while (src[i - 1])
		i++;
	ret_str = malloc(sizeof(*src) * i);
	if (ret_str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ret_str[i] = src[i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
