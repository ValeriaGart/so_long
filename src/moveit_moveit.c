/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit_moveit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:59:50 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/02 12:41:58 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/so_long.h"
#include <limits.h>

void	ft_write_moves(int moves, t_data *data)
{
	char	*str;

	str = ft_itoa(moves);
	if (!str)
		exit(1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->backgrd, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->backgrd, 64, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, INT_MAX, "Moves: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 10, INT_MAX, str);
	free(str);
}

void	ft_new_img(char *path, t_data *data)
{
	int	num;

	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, path, &num, &num);
}

void	ft_monke_moves(t_data *data, char *one, char *two)
{
	int	i;

	i = 0;
	ft_new_img(one, data);
	while (++i < 7000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
	i = 0;
	ft_new_img(two, data);
	while (++i < 5000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
}
 
void    move_monke(int keysym, t_data *data)
{
	int	num;

    data->moves += 1;
	ft_write_moves(data->moves, data);
    if ((keysym == XK_d || keysym == RIGHT_KEY) && (data->space[data->y][data->x + 1] != '1'))
	{ 
		data->x += 1;
		ft_monke_moves(data, "textures/maincharr1.xpm", "textures/maincharr2.xpm");
	}
	if ((keysym == XK_a || keysym == LEFT_KEY)  && (data->space[data->y][data->x - 1] != '1'))
	{
		data->x -= 1;
		ft_monke_moves(data, "textures/maincharl1.xpm", "textures/maincharl2.xpm");
	}
	if ((keysym == XK_w || keysym == UP_KEY) && (data->space[data->y - 1][data->x] != '1'))
	{
		data->y -= 1;
		ft_monke_moves(data, "textures/maincharu1.xpm", "textures/maincharu2.xpm");
	}
	if ((keysym == XK_s || keysym == DOWN_KEY)  && (data->space[data->y + 1][data->x] != '1'))
	{
		data->y += 1;
		ft_monke_moves(data, "textures/mainchard1.xpm", "textures/mainchard2.xpm");
	}
    if (data->space[data->y][data->x] == 'C')
    {
		data->col += 1;
        data->space[data->y][data->x] = '0';
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
	if (data->col == data->total_col)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->exit);
		data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/exit_open.xpm", &num, &num);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, data->ex * 64, data->ey * 64);
	}
    if (((data->col == data->total_col) && (data->space[data->y][data->x] == 'E'))
		|| data->space[data->y][data->x] == 'V')
		handle_keypress(XK_Escape, data);
}

void	ft_loop_weapon(t_data *data, int ind, int x, int y)
{
	int	num;

	mlx_destroy_image(data->mlx_ptr, data->img->weaponu);
	mlx_destroy_image(data->mlx_ptr, data->img->weapond);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponr);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponl);
	if (ind == 3)
	{
		data->img->weaponl = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponl3.xpm", &num, &num);
		data->img->weaponr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponr3.xpm", &num, &num);
		data->img->weapond = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weapond3.xpm", &num, &num);
		data->img->weaponu = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponu3.xpm", &num, &num);
	}
	if (ind == 2)
	{
		data->img->weaponl = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponl2.xpm", &num, &num);
		data->img->weaponr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponr2.xpm", &num, &num);
		data->img->weapond = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weapond2.xpm", &num, &num);
		data->img->weaponu = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponu2.xpm", &num, &num);
	}
	if (ind == 1)
	{
		data->img->weaponl = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponl1.xpm", &num, &num);
		data->img->weaponr = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponr1.xpm", &num, &num);
		data->img->weapond = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weapond1.xpm", &num, &num);
		data->img->weaponu = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weaponu1.xpm", &num, &num);
	}
	if (data->space[x + 1][y] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->weapond, y * 64, (x + 1) * 64);
	if (data->space[x - 1][y] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,  data->img->weaponu, y * 64, (x - 1) * 64);
	if (data->space[x][y + 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->weaponr, (y + 1) * 64, x * 64);
	if (data->space[x][y - 1] != '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->weaponl, (y - 1) * 64, x * 64);
}

void	ft_use_weapon_yo(t_data *data)
{
	int	num;
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
		data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, "textures/weapon.xpm", &num, &num);
	ft_loop_weapon(data, 3, data->y, data->x);
	while (++i < 20000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
	ft_loop_weapon(data, 2, data->y, data->x);
	while (++i < 40000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
	ft_loop_weapon(data, 1, data->y, data->x);
	while (++i < 60000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
}

void	ft_defeat_villain(t_data *data, int x, int y)
{
	int	num;

	if (data->space[x][y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, y * 64, x * 64);
	if (data->space[x][y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->col, y * 64, x * 64);
	if (data->space[x][y] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, y * 64, x * 64);
	if (data->space[x][y] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, y * 64, x * 64);
	if (data->space[x][y] == 'V')
	{
		data->space[x][y] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->prize, y * 64, x * 64);
	}
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, "textures/mainchar.xpm", &num, &num);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->monki, data->x * 64, data->y * 64);
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

int	handle_keypress(int keysym, t_data *data)
{
	int	num;

	if (keysym == XK_Escape)
		ft_free_all(data, data->map);
	if (keysym == XK_q)
		return (ft_destroy_it_roarrr(data));
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	data->img->monki = mlx_xpm_file_to_image(data->mlx_ptr, "textures/mainchar.xpm", &num, &num);
	if (data->space[data->y][data->x] != 'E' && data->space[data->y][data->x] != 'V')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->right, data->x * 64, data->y * 64);
	else if (data->space[data->y][data->x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->exit, data->x * 64, data->y * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->villain, data->x * 64, data->y * 64);
	move_monke(keysym, data);
	return (0);
}