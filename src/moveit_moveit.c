/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit_moveit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:59:50 by vharkush          #+#    #+#             */
/*   Updated: 2023/03/23 19:59:56 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/so_long.h"

void    move_monke(int keysym, t_data *data)
{
	int	num;
    data->moves += 1;
    printf("Moves: %d\n", data->moves);
    if ((keysym == XK_d) && (data->space[data->y][data->x + 1] != '1'))
		data->x += 1;
	if (keysym == XK_a && (data->space[data->y][data->x - 1] != '1'))
		data->x -= 1;
	if (keysym == XK_w && (data->space[data->y - 1][data->x] != '1'))
		data->y -= 1;
	if (keysym == XK_s && (data->space[data->y + 1][data->x] != '1'))
		data->y += 1;
    if (data->space[data->y][data->x] == 'C')
    {
		data->col += 1;
        data->space[data->y][data->x] = '0';
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
	if (data->col == data->total_col)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->exit);
		data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/exit_closed.xpm", &num, &num);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, data->ex * 64, data->ey * 64);
	}
    if ((data->col == data->total_col) && (data->space[data->y][data->x] == 'E'))
		handle_keypress(XK_Escape, data);
}

int	handle_keypress(int keysym, t_data *data)
{
	int	num;

	if (keysym == XK_Escape)
		ft_free_all(data, data->map);
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, "textures/mainchar.xpm", &num, &num);
	if (data->space[data->y][data->x] != 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, data->x * 64, data->y * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, data->x * 64, data->y * 64);
	move_monke(keysym, data);
	return (0);
}