/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:09 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/06 20:47:26 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_bonhomme(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->player_up, data->p_x * IMG_W, data->p_y * IMG_H);
}

void	ft_put_bottom(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom,
			x, data->size_y - IMG_H);
		x += IMG_W;
	}
	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background,
			x, data->size_y - (2 * IMG_H));
		x += IMG_W;
	}
	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->top,
			x, data->size_y - (3 * IMG_H));
		x += IMG_W;
	}
}

static void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y - 3)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

static void	ft_fill_map(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'P')
		ft_put_bonhomme(data);
	else if (data->map->map[y][x] == '1')
		ft_put_stuff(data);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->map->coin,
			x * IMG_W, y * IMG_H);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->map->home,
			x * IMG_W, y * IMG_H);
	else if (data->map->map[y][x] == 'V')
		mlx_put_image_to_window(data->mlx, data->win, data->img->bad_up,
			x * IMG_W, y * IMG_H);
	else if (data->map->map[y][x] == 'H')
		mlx_put_image_to_window(data->mlx, data->win, data->img->bad_right,
			x * IMG_W, y * IMG_H);
}

void	ft_put_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	ft_put_background(data);
	ft_put_bottom(data);
	while (data->map->y < ((data->size_y - 3) / IMG_H) - 2)
	{
		ft_fill_map(data, data->map->x, data->map->y);
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
