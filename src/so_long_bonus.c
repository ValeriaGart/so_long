/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:16:24 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 14:21:57 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	*assign_img_mlx(char *path, void *mlx_ptr)
{
	void	*ret;
	int		num;

	ret = mlx_xpm_file_to_image(mlx_ptr, path, &num, &num);
	return (ret);
}

void	ft_assign_img(t_data *data, t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	data->img = img;
	data->img->prize = assign_img_mlx("textures/prize.xpm", data->mlx_ptr);
	data->img->backgrd = assign_img_mlx("textures/walll.xpm", data->mlx_ptr);
	data->img->right = assign_img_mlx("textures/ground_colour.xpm",
			data->mlx_ptr);
	data->img->monki = assign_img_mlx("textures/mainchar.xpm", data->mlx_ptr);
	data->img->exit = assign_img_mlx("textures/exit_closed.xpm", data->mlx_ptr);
	data->img->col = assign_img_mlx("textures/collectable.xpm", data->mlx_ptr);
	data->img->villain = assign_img_mlx("textures/enemy1.xpm", data->mlx_ptr);
	data->img->weaponl = assign_img_mlx("textures/wl3.xpm", data->mlx_ptr);
	data->img->weaponr = assign_img_mlx("textures/wr3.xpm", data->mlx_ptr);
	data->img->weapond = assign_img_mlx("textures/wd3.xpm", data->mlx_ptr);
	data->img->weaponu = assign_img_mlx("textures/wu3.xpm", data->mlx_ptr);
	ft_put_img(data, map, 0, 0);
}

void	ft_put_enemy(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->space[x] != NULL)
	{
		y = 0;
		while (data->space[x][y] != '\0')
		{
			if (data->space[x][y] == 'V')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->villain, y * 64, x * 64);
			y++;
		}
		x++;
	}
}

int	ft_loop_enemy(t_data *data)
{
	data->i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = assign_img_mlx("textures/enemy2.xpm", data->mlx_ptr);
	usleep(80000);
	ft_put_enemy(data);
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = assign_img_mlx("textures/enemy3.xpm", data->mlx_ptr);
	usleep(80000);
	ft_put_enemy(data);
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = assign_img_mlx("textures/enemy1.xpm", data->mlx_ptr);
	usleep(80000);
	ft_put_enemy(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	data.i = 0;
	map.villain = 0;
	ft_pregame(&map, &data, av, ac);
	data.space = map.space;
	data.map = &map;
	ft_assign_img(&data, data.map);
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	if (data.map->villain)
		mlx_loop_hook(data.mlx_ptr, &ft_loop_enemy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
