/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:09 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/03 14:54:53 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_bonhomme(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, data->p_x * IMG_W, data->p_y * IMG_H);
}

static void	ft_put_stuff(t_data *data, char *texture_path)
{
	int	w;
	int h;
	data->map->object = mlx_xpm_file_to_image(data->mlx, texture_path, &w, &h);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object, (data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_put_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_bonhomme(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_stuff(data, "./textures/mapvoid.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_stuff(data, "./textures/money.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_stuff(data, "./textures/home.xpm");
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}