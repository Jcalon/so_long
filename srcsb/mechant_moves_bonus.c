/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechant_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:11:27 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:42:46 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	go_right(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'H' && data->map->map[y][x + 1] != '1'
			&& data->map->map[y][x + 1] != 'E'
			&& data->map->map[y][x + 1] != 'C'
			&& data->map->map[y][x + 1] != 'V'
			&& data->map->map[y][x + 1] != 'H')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, x * IMG_W, y * IMG_W);
		data->map->map[y][x] = '0';
		data->map->map[y][x + 1] = 'H';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bad_right, (x + 1) * IMG_W, y * IMG_H);
		return (1);
	}
	return (0);
}

int	go_left(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'H' && data->map->map[y][x - 1] != '1'
			&& data->map->map[y][x - 1] != 'E'
			&& data->map->map[y][x - 1] != 'C'
			&& data->map->map[y][x - 1] != 'V'
			&& data->map->map[y][x - 1] != 'H')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, x * IMG_W, y * IMG_W);
		data->map->map[y][x] = '0';
		data->map->map[y][x - 1] = 'H';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bad_left, (x - 1) * IMG_W, y * IMG_H);
		return (1);
	}
	return (0);
}

int	go_front(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'V' && data->map->map[y + 1][x] != '1'
			&& data->map->map[y + 1][x] != 'E'
			&& data->map->map[y + 1][x] != 'C'
			&& data->map->map[y + 1][x] != 'V'
			&& data->map->map[y + 1][x] != 'H')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, x * IMG_W, y * IMG_W);
		data->map->map[y][x] = '0';
		data->map->map[y + 1][x] = 'V';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bad_up, x * IMG_W, (y + 1) * IMG_H);
		return (1);
	}
	return (0);
}

int	go_back(t_data *data, int x, int y)
{
	if (data->map->map[y][x] == 'V'
			&& data->map->map[y - 1][x] != '1'
			&& data->map->map[y - 1][x] != 'E'
			&& data->map->map[y - 1][x] != 'C'
			&& data->map->map[y - 1][x] != 'H'
			&& data->map->map[y - 1][x] != 'V')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, x * IMG_W, y * IMG_W);
		data->map->map[y][x] = '0';
		data->map->map[y - 1][x] = 'V';
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bad_down, x * IMG_W, (y - 1) * IMG_H);
		return (1);
	}
	return (0);
}
