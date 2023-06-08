/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:06:19 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 15:22:23 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	ft_open_map(char **av, t_map *map, t_data *data)
{
	int		fd;
	char	*ber;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nMap openning failed\n");
		exit (1);
	}
	ber = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (!ber || (ft_strlen(ber) != 4))
		ft_error_msg_exit_free_fd(fd, "Error\nMap is not .ber\n", 22);
	ft_check_map(fd, av, map, data);
	if (!map->space)
		ft_error_msg_exit_free_fd(42, "Error\nMalloc failed\n", 20);
	data->space = map->space;
	data->col = 0;
	data->moves = 0;
	data->total_col = map->collect;
	close(fd);
}

void	ft_put_with_mlx(t_data *data, void *pic, int x, int y)
{
	x *= 64;
	y *= 64;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, pic, x, y);
}

void	ft_put_img(t_data *data, t_map *map, int i, int j)
{
	while (i < map->lines)
	{
		j = 0;
		while (map->space[i][j])
		{
			if (map->space[i][j] == '1')
				ft_put_with_mlx(data, data->img->backgrd, j, i);
			else
				ft_put_with_mlx(data, data->img->right, j, i);
			if (map->space[i][j] == 'C')
				ft_put_with_mlx(data, data->img->col, j, i);
			if (map->space[i][j] == 'E')
				ft_put_with_mlx(data, data->img->exit, j, i);
			if (map->space[i][j] == 'P')
			{
				ft_put_with_mlx(data, data->img->monki, j, i);
				data->x = j;
				data->y = i;
			}
			if (map->space[i][j] == 'V')
				ft_put_with_mlx(data, data->img->villain, j, i);
			j++;
		}
		i++;
	}
}

void	ft_pregame(t_map *map, t_data *data, char **av, int ac)
{
	if (ac != 2 || (ft_strlen(av[1]) <= 4))
		ft_error_msg_exit_free_fd(42, "Error\nWrong args:-(\n", 20);
	ft_open_map(av, map, data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_free_arr(map);
		ft_error_msg_exit_free_fd(42, "Error\nMlx_init failed\n", 22);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, map->line_len * 64,
			map->lines * 64, "De monke");
	if (data->win_ptr == NULL)
	{
		ft_free_arr(map);
		ft_error_msg_exit_free_fd(42, "Error\nMlx_new_window failed\n", 28);
	}
}

void	ft_write_moves(int moves, t_data *data)
{
	char	*str;

	str = ft_itoa(moves);
	if (!str)
		ft_free_all(data, data->map);
	ft_put_with_mlx(data, data->img->backgrd, 0, 0);
	ft_put_with_mlx(data, data->img->backgrd, 0, 64);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, INT_MAX, "Moves: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 10, INT_MAX, str);
	free(str);
}
