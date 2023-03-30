#include "../incl/so_long.h"

void    ft_free_all(t_data *data, t_map *map)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img->backgrd);
	mlx_destroy_image(data->mlx_ptr, data->img->right);
    mlx_destroy_image(data->mlx_ptr, data->img->monki);
    mlx_destroy_image(data->mlx_ptr, data->img->col);
    mlx_destroy_image(data->mlx_ptr, data->img->exit);
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