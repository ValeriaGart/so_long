/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:23:38 by vharkush          #+#    #+#             */
/*   Updated: 2023/06/01 13:26:56 by vharkush         ###   ########.fr       */
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
# define DOWN_KEY 65364
# define UP_KEY 65362
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

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
	int				villain;
	int				x;
	int				y;
}		t_map;

typedef struct s_img
{
	void	*col;
	void	*exit;
	void	*right;
	void	*prize;
	void	*backgrd;
	void	*monki;
	void	*villain;
	void	*weaponl;
	void	*weaponr;
	void	*weapond;
	void	*weaponu;
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
	int		i;
	t_img	*img;
	t_map	*map;
}	t_data;

void	ft_check_boarder(t_map *map, int i, char **iter);
void	ft_check_map(int fd, char **av, t_map *map, t_data *data);
void	ft_lines(int fd, t_map *map);
void	ft_free_arr(t_map *map);
void	ft_free_all(t_data *data, t_map *map);
void	ft_put_img(t_data *data, t_map *map, int i, int j);
void	ft_open_map(char **av, t_map *map, t_data *data);
void	ft_pregame(t_map *map, t_data *data, char **av, int ac);
void	ft_error_msg_exit_free_fd(int fd, char *msg,int len);
char	**ft_store_arr(t_map *map, int fd);
int		handle_keypress(int keysym, t_data *data);
int		handle_x(t_data *data);

#endif
