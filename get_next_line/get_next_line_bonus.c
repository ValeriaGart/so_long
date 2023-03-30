/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:23:19 by vharkush          #+#    #+#             */
/*   Updated: 2022/11/10 20:23:25 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_if_newline(int i, char ***line)
{
	char	*ret;
	char	*temp;
	int		rem_i;

	rem_i = i + 1;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	ret = ft_memcpy(ret, **line, i + 1);
	ret[i + 1] = '\0';
	i = ft_strlen(**line) - i;
	temp = malloc(sizeof(char) * i);
	if (!temp)
		return (NULL);
	temp[i - 1] = '\0';
	temp = ft_memcpy(temp, **line + rem_i, i - 1);
	free (**line);
	**line = ft_strdup(temp);
	free (temp);
	return (ret);
}

char	*ft_no_newline(int i, char ***line, int fd)
{
	char	*temp;
	char	*ret;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	i = read(fd, temp, BUFFER_SIZE);
	if (i < 0 || (i == 0 && **line[0] == 0))
	{
		free (**line);
		**line = NULL;
		free (temp);
		return (NULL);
	}
	temp[i] = '\0';
	ret = ft_strjoin(**line, temp);
	free (temp);
	free (**line);
	**line = NULL;
	if (i < BUFFER_SIZE && ft_int_strchr(ret, '\n') == -1)
		return (ret);
	**line = ft_strdup(ret);
	free (ret);
	return ("yo");
}

char	*ft_gimme_string(char **line, int fd)
{
	int		i;
	char	*ret;

	i = ft_int_strchr(*line, '\n');
	if (i >= 0)
		return (ft_if_newline(i, &line));
	else
	{
		ret = ft_no_newline(i, &line, fd);
		if (ret == NULL || *line == NULL)
			return (ret);
	}
	return (ft_gimme_string(line, fd));
}

char	*get_next_line(int fd)
{
	static char	*line[10000];
	char		*ret;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!line[fd])
	{
		line[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!line[fd])
			return (NULL);
		size = read(fd, line[fd], BUFFER_SIZE);
		if (size <= 0)
		{
			free (line[fd]);
			line[fd] = NULL;
			return (NULL);
		}
		line[fd][size] = '\0';
	}
	ret = ft_gimme_string(&line[fd], fd);
	return (ret);
}
