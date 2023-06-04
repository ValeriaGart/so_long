/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:17:54 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 14:57:14 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	ft_change_index(int turn, int cur, char axis)
{
	int	i;

	i = 0;
	if ((turn == 0 && axis == 'y') || (turn == 3 && axis == 'x'))
		i = -1;
	if ((turn == 1 && axis == 'x') || (turn == 2 && axis == 'y'))
		i = 1;
	return (cur + i);
}

void	ft_recursive_fun(t_map *map, t_data *data, int x, int y)
{
	char	**space;
	int		new_x;
	int		new_y;
	int		i;

	space = map->space;
	i = -1;
	while (++i < 5)
	{
		new_x = ft_change_index(i, x, 'x');
		new_y = ft_change_index(i, y, 'y');
		if (space[new_x][new_y] != '1')
		{
			if (space[new_x][new_y] == 'C')
				map->col_way += 1;
			if (space[new_x][new_y] == 'E')
			{
				map->exit_way += 1;
				data->ex = new_y;
				data->ey = new_x;
			}
			map->space[new_x][new_y] = '1';
			ft_recursive_fun(map, data, new_x, new_y);
		}
	}
}

void	ft_de_monkey_path(t_map *map, t_data *data)
{
	char	**space;

	space = map->space;
	map->x = 0;
	while (map->x < map->lines)
	{
		map->y = 0;
		while (map->y < (int)map->line_len)
		{
			if (space[map->x][map->y] == 'P')
				break ;
			map->y += 1;
		}
		if (space[map->x][map->y] == 'P')
			break ;
		map->x += 1;
	}
	ft_recursive_fun(map, data, map->x, map->y);
	if (map->col_way != map->collect || map->exit_way < 1
		|| !map->collect)
	{
		ft_free_arr(map);
		exit (write(1, "Error\nNo chance to win!\n", 24));
	}
	ft_free_arr(map);
}

void	ft_set_to_null_send_to_check(t_map *map)
{
	if (!map->space)
		ft_error_msg_exit_free_fd(42, "Error\nMalloc failed\n", 20);
	map->collect = 0;
	map->exit = 0;
	map->player = 0;
	map->exit_way = 0;
	map->col_way = 0;
	ft_check_boarder(map, 0, map->space);
}

void	ft_check_map(int fd, char **av, t_map *map, t_data *data)
{
	ft_lines(fd, map);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap openning failed\n");
		exit (1);
	}
	map->space = ft_store_arr(map, fd, -1);
	close(fd);
	ft_set_to_null_send_to_check(map);
	if (map->exit == 0 || map->player == 0)
	{
		ft_free_arr(map);
		exit (write(1, "Error\nNo player or exit, check properly!\n", 42));
	}
	ft_de_monkey_path(map, data);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap openning failed\n");
		exit (1);
	}
	map->space = ft_store_arr(map, fd, -1);
}
