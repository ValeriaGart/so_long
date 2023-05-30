/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveit_moveit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:59:50 by vharkush          #+#    #+#             */
/*   Updated: 2023/05/30 22:34:17 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incl/so_long.h"

void	ft_write_moves(int moves)
{
	int		tmp;
	int		rem_moves;
	char	print;

	tmp = 0;
	rem_moves = moves;
	write(1, "Moves: ", 7);
	while (moves != 0)
	{
		tmp = tmp * 10 + (moves % 10);
		moves /= 10;
	}
	while (tmp != 0)
	{
		print = tmp % 10 + 48;
		tmp /= 10;
		write(1, &print, 1);
	}
	if (rem_moves % 10 == 0 && rem_moves != 0)
		while (rem_moves % 10 == 0)
		{
			write(1, "0", 1);
			rem_moves /= 10;
		}
	write(1, "\n", 1);
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
	ft_write_moves(data->moves);
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


/*void	ft_put_enemy(t_data *data)
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
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->villain, y * 64, x * 64);
			y++;
		}
		x++;
	}
}*/

/*int	ft_loop_enemy(t_data *data)
{
	int	num;

	data->i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy2.xpm", &num, &num);
	while (data->i < 10000)
	{
		ft_put_enemy(data);
		data->i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy3.xpm", &num, &num);
	while (data->i < 20000)
	{
		ft_put_enemy(data);
		data->i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	data->img->villain = mlx_xpm_file_to_image(data->mlx_ptr, "textures/enemy1.xpm", &num, &num);
	ft_put_enemy(data);
	return (0);
}*/

int	handle_keypress(int keysym, t_data *data)
{
	int	num;

	if (keysym == XK_Escape)
		ft_free_all(data, data->map);
	//if (keysym == XK_q)
	//{
	//	ft_loop_enemy(data);
	//	return (0);
	//}
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