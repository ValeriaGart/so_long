/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:16:24 by vharkush          #+#    #+#             */
/*   Updated: 2023/03/23 17:48:55 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_open_map(char **av, t_map *map, t_data *data)
{
	int		fd;
	char	*ber;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\nMap openning failed\n");
		exit (1);
	}
	ber = ft_strnstr(av[1], ".ber", ft_strlen(av[1]));
	if (!ber || (ft_strlen(ber) != 4))
	{
		close(fd);
		write(1, "ERROR\nMap is not .ber\n", 23);
		exit (1);
	}
	ft_check_map(fd, av, map, data);
	data->space = map->space;
	data->col = 0;
	data->moves = 0;
	data->total_col = map->collect;
	close(fd);
}

void	ft_put_img(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (map->space[i][j])
		{
			if (map->space[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->backgrd, j * 64, i * 64);
			else
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, j * 64, i * 64);
			if (map->space[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->col, j * 64, i * 64);
			if (map->space[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, j * 64, i * 64);
			if (map->space[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, j * 64, i * 64);
				data->x = j;
				data->y = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_assign_img(t_data *data, t_map *map)
{
	t_img	*img;
	int		num;

	img = malloc(sizeof(t_img));
	data->img = img;
	data->img->backgrd = mlx_xpm_file_to_image(data->mlx_ptr, "textures/walll.xpm", &num, &num);
	data->img->right = mlx_xpm_file_to_image(data->mlx_ptr, "textures/ground_colour.xpm", &num, &num);
	data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, "textures/mainchar.xpm", &num, &num);
	data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/exit_closed.xpm", &num, &num);
	data->img->col = mlx_xpm_file_to_image(data->mlx_ptr, "textures/collectable.xpm", &num, &num);
	ft_put_img(data, map);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	if (ac != 2 || (ft_strlen(av[1]) == 4))
		return (write(1, "ERROR\nWrong args:-(\n", 21));
	ft_open_map(av, &map, &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		ft_free_arr(&map);
		return (write(1, "ERROR\nMlx_init failed\n", 23));
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, map.line_len * 64,
			map.lines * 64, "De monke");
	if (data.win_ptr == NULL)
	{
		ft_free_arr(&map);
		return (write(1, "ERROR\nMlx_new_window failed\n", 29));
	}
	data.space = map.space;
	data.map = &map;
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	ft_assign_img(&data, &map);
	mlx_loop(data.mlx_ptr);
	return (1);
}
