/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:16:24 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/30 17:59:43 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

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
	data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy1.xpm", &num, &num);
	ft_put_img(data, map, 0, 0);
}

void	ft_put_enemy(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->space[x] != NULL)
	{
		printf("%d\n", data->i);
		y = 0;
		while (data->space[x][y] != '\0')
		{
			if (data->space[x][y] == 'V')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->villain, x * 64, y * 64);
			y++;
		}
	x++;
	}
}

void	ft_loop_enemy(t_data *data)
{
	int	num;

	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	if (data->i < 3)
		data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy2.xpm", &num, &num);
	else if(data->i < 6000)
		data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy3.xpm", &num, &num);
	if (data->i == 500)
		data->i = 0;
	ft_put_enemy(data);
	data->i += 1;
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	data.i = 0;
	ft_pregame(&map, &data, av, ac);
	data.space = map.space;
	data.map = &map;
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	ft_assign_img(&data, &map);
	ft_loop_enemy(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
