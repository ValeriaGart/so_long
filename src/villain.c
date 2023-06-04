/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:04:55 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 15:05:25 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_new_weapon_frame(int ind, t_data *data)
{
	if (ind == 3)
	{
		data->img->weaponl = assign_img_mlx("textures/wl3.xpm", data->mlx_ptr);
		data->img->weaponr = assign_img_mlx("textures/wr3.xpm", data->mlx_ptr);
		data->img->weapond = assign_img_mlx("textures/wd3.xpm", data->mlx_ptr);
		data->img->weaponu = assign_img_mlx("textures/wu3.xpm", data->mlx_ptr);
	}
	if (ind == 2)
	{
		data->img->weaponl = assign_img_mlx("textures/wl2.xpm", data->mlx_ptr);
		data->img->weaponr = assign_img_mlx("textures/wr2.xpm", data->mlx_ptr);
		data->img->weapond = assign_img_mlx("textures/wd2.xpm", data->mlx_ptr);
		data->img->weaponu = assign_img_mlx("textures/wu2.xpm", data->mlx_ptr);
	}
	if (ind == 1)
	{
		data->img->weaponl = assign_img_mlx("textures/wl1.xpm", data->mlx_ptr);
		data->img->weaponr = assign_img_mlx("textures/wr1.xpm", data->mlx_ptr);
		data->img->weapond = assign_img_mlx("textures/wd1.xpm", data->mlx_ptr);
		data->img->weaponu = assign_img_mlx("textures/wu1.xpm", data->mlx_ptr);
	}
}

void	ft_loop_weapon(t_data *data, int ind, int x, int y)
{
	mlx_destroy_image(data->mlx_ptr, data->img->weaponu);
	mlx_destroy_image(data->mlx_ptr, data->img->weapond);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponr);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponl);
	ft_new_weapon_frame(ind, data);
	if (data->space[x + 1][y] != '1')
		ft_put_with_mlx(data, data->img->weapond, y, x + 1);
	if (data->space[x - 1][y] != '1')
		ft_put_with_mlx(data, data->img->weaponu, y, x - 1);
	if (data->space[x][y + 1] != '1')
		ft_put_with_mlx(data, data->img->weaponr, y + 1, x);
	if (data->space[x][y - 1] != '1')
		ft_put_with_mlx(data, data->img->weaponl, y - 1, x);
}

void	ft_use_weapon_yo(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = assign_img_mlx("textures/weapon.xpm", data->mlx_ptr);
	ft_loop_weapon(data, 3, data->y, data->x);
	while (++i < 20000)
		ft_put_with_mlx(data, data->img->monki, data->x, data->y);
	ft_loop_weapon(data, 2, data->y, data->x);
	while (++i < 40000)
		ft_put_with_mlx(data, data->img->monki, data->x, data->y);
	ft_loop_weapon(data, 1, data->y, data->x);
	while (++i < 60000)
		ft_put_with_mlx(data, data->img->monki, data->x, data->y);
}

void	ft_defeat_villain(t_data *data, int x, int y)
{
	if (data->space[x][y] == 'E')
		ft_put_with_mlx(data, data->img->exit, y, x);
	if (data->space[x][y] == 'C')
		ft_put_with_mlx(data, data->img->col, y, x);
	if (data->space[x][y] == '0')
		ft_put_with_mlx(data, data->img->right, y, x);
	if (data->space[x][y] == 'P')
		ft_put_with_mlx(data, data->img->right, y, x);
	if (data->space[x][y] == 'V')
	{
		data->space[x][y] = '0';
		ft_put_with_mlx(data, data->img->prize, y, x);
	}
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = assign_img_mlx("textures/mainchar.xpm", data->mlx_ptr);
	ft_put_with_mlx(data, data->img->monki, data->x, data->y);
}

int	ft_destroy_it_roarrr(t_data *data)
{
	int	y;
	int	x;

	x = data->y;
	y = data->x;
	ft_use_weapon_yo(data);
	ft_defeat_villain(data, x + 1, y);
	ft_defeat_villain(data, x - 1, y);
	ft_defeat_villain(data, x, y + 1);
	ft_defeat_villain(data, x, y - 1);
	return (0);
}
