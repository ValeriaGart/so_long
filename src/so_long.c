/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:16:24 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/29 15:14:42 by vharkush         ###   ########.fr       */
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
	ft_put_img(data, map, 0, 0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	data;

	ft_pregame(&map, &data, av, ac);
	data.space = map.space;
	data.map = &map;
	mlx_hook(data.win_ptr, 17, 1L << 2, &handle_x, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	ft_assign_img(&data, &map);
	mlx_loop(data.mlx_ptr);
	return (0);
}
