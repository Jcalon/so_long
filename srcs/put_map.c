/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:09 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:44:48 by jcalon           ###   ########.fr       */
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

static void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
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
}

void	ft_put_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	ft_put_background(data);
	while (data->map->y < ((data->size_y) / IMG_H))
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
