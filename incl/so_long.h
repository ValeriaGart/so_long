/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:23:38 by vharkush          #+#    #+#             */
/*   Updated: 2023/03/16 21:24:16 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	char			**space;
	unsigned long	line_len;
	int				lines;
	int				collect;
	int				col_way;
	int				exit_way;
	int				player;
	int				exit;
	int				x;
	int				y;
}		t_map;

typedef struct s_img
{
	void	*col;
	void	*exit;
	void	*right;
	void	*backgrd;
	void	*monki;
}		t_img;

typedef struct s_data
{
	char	**space;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		ex;
	int		ey;
	int		col;
	int		total_col;
	int		moves;
	t_img	*img;
	t_map	*map;
}	t_data;

void	ft_check_boarder(t_map *map, int i, char **iter);
void	ft_check_map(int fd, char **av, t_map *map, t_data *data);
void	ft_lines(int fd, t_map *map);
void	ft_free_arr(t_map *map);
void	ft_free_all(t_data *data, t_map *map);
char	**ft_store_arr(t_map *map, int fd);
int		handle_keypress(int keysym, t_data *data);
int		handle_x(t_data *data);

#endif
