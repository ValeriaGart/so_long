/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:16:24 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/11 14:10:53 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

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
	data->img->backgrd = assign_img_mlx("textures/walll.xpm", data->mlx_ptr);
	data->img->right = assign_img_mlx("textures/ground_colour.xpm",
			data->mlx_ptr);
	data->img->monki = assign_img_mlx("textures/mainchar.xpm", data->mlx_ptr);
	data->img->exit = assign_img_mlx("textures/exit_closed.xpm", data->mlx_ptr);
	data->img->col = assign_img_mlx("textures/collectable.xpm", data->mlx_ptr);
	ft_put_img(data, map, 0, 0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	data.i = 0;
	data.moves = 0;
	ft_pregame(&map, &data, av, ac);
	data.space = map.space;
	data.map = &map;
	ft_assign_img(&data, data.map);
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
