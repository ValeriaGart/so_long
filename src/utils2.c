/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 15:01:50 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 15:03:11 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_new_img(char *path, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = assign_img_mlx(path, data->mlx_ptr);
}

void	if_lrud(int keysym, t_data *data)
{
	if ((keysym == XK_d || keysym == RIGHT_KEY)
		&& (data->space[data->y][data->x + 1] != '1'))
	{
		data->x += 1;
		ft_monke_moves(data, "textures/mainr1.xpm", "textures/mainr2.xpm");
	}
	if ((keysym == XK_a || keysym == LEFT_KEY)
		&& (data->space[data->y][data->x - 1] != '1'))
	{
		data->x -= 1;
		ft_monke_moves(data, "textures/mainl1.xpm", "textures/mainl2.xpm");
	}
	if ((keysym == XK_w || keysym == UP_KEY)
		&& (data->space[data->y - 1][data->x] != '1'))
	{
		data->y -= 1;
		ft_monke_moves(data, "textures/mainu1.xpm", "textures/mainu2.xpm");
	}
	if ((keysym == XK_s || keysym == DOWN_KEY)
		&& (data->space[data->y + 1][data->x] != '1'))
	{
		data->y += 1;
		ft_monke_moves(data, "textures/maind1.xpm", "textures/maind2.xpm");
	}
}
