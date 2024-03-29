/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:33:16 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:44:17 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define IMG_W 40
# define IMG_H 40
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_img
{
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*background;
	void	*left;
	void	*top;
	void	*bottom;
	void	*right;
	void	*rtcorner;
	void	*ltcorner;
	void	*lbcorner;
	void	*rbcorner;
}				t_img;

typedef struct s_map
{
	char	**map;
	void	*home;
	void	*coin;
	void	*hole;
	int		x;
	int		y;
	int		money;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_img	*img;
}				t_data;

void	ft_win_dim(t_data *data, char **argv);
void	struct_init(t_data *data, t_map *map);
void	parse_map(t_data *data, char **argv);

void	ft_put_stuff(t_data *data);
void	ft_put_map(t_data *data);

void	ft_move(t_data *data, char p, int dir);

int		go_right(t_data *data, int x, int y);
int		go_left(t_data *data, int x, int y);
int		go_front(t_data *data, int x, int y);
int		go_back(t_data *data, int x, int y);

int		ft_end(t_data *data, int win, char *str);
void	ft_perror(char *str);
int		ft_close(t_data *data);

#endif