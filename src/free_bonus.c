/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:42:33 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/04 15:16:57 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	ft_free_all(t_data *data, t_map *map)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img->backgrd);
	mlx_destroy_image(data->mlx_ptr, data->img->right);
	mlx_destroy_image(data->mlx_ptr, data->img->monki);
	mlx_destroy_image(data->mlx_ptr, data->img->col);
	mlx_destroy_image(data->mlx_ptr, data->img->exit);
	mlx_destroy_image(data->mlx_ptr, data->img->villain);
	mlx_destroy_image(data->mlx_ptr, data->img->prize);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponl);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponr);
	mlx_destroy_image(data->mlx_ptr, data->img->weaponu);
	mlx_destroy_image(data->mlx_ptr, data->img->weapond);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	ft_free_arr(map);
	exit (0);
}

int	handle_x(t_data *data)
{
	ft_free_all(data, data->map);
	exit(0);
}

void	ft_error_msg_exit_free_fd(int fd, char *msg, int len)
{
	if (fd != 42)
		close(fd);
	if (msg)
		write(1, msg, len);
	exit (1);
}
