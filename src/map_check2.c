/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:18:31 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/29 16:28:24 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_lines(int fd, t_map *map)
{
	char	*tmp;

	tmp = get_next_line(fd, 0);
	if (!tmp)
		ft_error_msg_exit_free_fd(fd, "Error\nNot enough lines in a file\n", 33);
	map->lines = 0;
	map->line_len = ft_strlen(tmp) - 1;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd, 0);
		if (tmp && (map->line_len != (ft_strlen(tmp) - 1)))
		{
			free(tmp);
			get_next_line(-1, 1);
			ft_error_msg_exit_free_fd(fd, "Error\nlines r not same length\n", 30);
		}
		map->lines += 1;
	}
	free(tmp);
}

char	**ft_store_arr(t_map *map, int fd)
{
	char	**str;
	int		i;
	int		pos_err;

	str = malloc((map->lines) * sizeof(char *));
	i = -1;
	pos_err = 0;
	while (++i < map->lines && str != NULL)
	{
		str[i] = malloc((map->line_len + 1) * sizeof(char));
		if (str[i])
			pos_err = read(fd, str[i], map->line_len + 1);
		if (str[i] == NULL || pos_err <= 0)
		{
			if (i)
				while (--i)
					free(str[i]);
			if (str[0])
				free(str[0]);
			free(str);
			ft_error_msg_exit_free_fd(fd, "Error\nRead or malloc error:-(\n", 30);
		}
		str[i][map->line_len] = '\0';
	}
	return (str);
}

void	ft_free_arr(t_map *map)
{
	int		i;
	char	**freee;

	i = 0;
	freee = map->space;
	if (freee)
	{
		while (i < map->lines)
		{
			free(freee[i]);
			i++;
		}
		free(freee);
	}
}

void	ft_check_more(char **iter, int i, t_map *map)
{
	int	j;

	j = 0;
	if (iter[i][0] != '1' || iter[i][map->line_len - 1] != '1'
		|| map->exit > 1 || map->player > 1)
	{
		ft_free_arr(map);
		exit (write(1, "Error\nThe map isn't correct\n", 29));
	}
	while (iter[i][j])
	{
		if (iter[i][j] != '1' && iter[i][j] != 'P' && iter[i][j] != 'C'
			&& iter[i][j] != 'E' && iter[i][j] != '0')
		{
			ft_free_arr(map);
			exit (write(1, "Error\nWrong symbols in the map\n", 32));
		}
		if (iter[i][j] == 'C')
			map->collect += 1;
		if (iter[i][j] == 'E')
			map->exit += 1;
		if (iter[i][j] == 'P')
			map->player += 1;
		j++;
	}
}

void	ft_check_boarder(t_map *map, int i, char **iter)
{
	int	j;

	j = 0;
	if (i == map->lines)
		return ;
	if (i == 0 || i == map->lines - 1)
	{
		while (iter[i][j])
		{
			if (iter[i][j] != '1')
			{
				ft_free_arr(map);
				ft_error_msg_exit_free_fd(42, "Error\nThe map isn't correct\n", 28);
			}
			j++;
		}
	}
	else
		ft_check_more(iter, i, map);
	ft_check_boarder(map, i + 1, iter);
}
