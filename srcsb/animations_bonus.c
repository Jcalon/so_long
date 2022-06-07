/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:01:54 by crazyd            #+#    #+#             */
/*   Updated: 2022/06/07 11:53:06 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_mechant_horizontal(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (data->size_y / IMG_H) - 3)
	{
		if (data->animations <= 500)
		{
			if (go_right(data, x, y) == 1)
				x++;
		}
		else if (data->animations > 500 && data->animations <= 1000)
			go_left(data, x, y);
		if (x < (data->size_x / IMG_W))
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
}

void	ft_move_mechant_vertical(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (data->size_y / IMG_H) - 3)
	{
		if (data->animations <= 500)
		{
			if (go_front(data, x, y) == 1)
				y++;
		}
		else if (data->animations > 500 && data->animations <= 1000)
			go_back(data, x, y);
		if (x < (data->size_x / IMG_W))
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
}

static void	ft_anim_2(t_data *data)
{
	int	img_w;
	int	img_h;

	if (data->animations > 500 && data->animations <= 750)
	{
		mlx_destroy_image(data->mlx, data->map->coin);
		data->map->coin = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin2.xpm", &img_w, &img_h);
		mlx_put_image_to_window(data->mlx, data->win,
			data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
	}
	else if (data->animations <= 1000)
	{
		mlx_destroy_image(data->mlx, data->map->coin);
		data->map->coin = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin3.xpm", &img_w, &img_h);
		mlx_put_image_to_window(data->mlx, data->win,
			data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
	}
}

static void	ft_anim_1(t_data *data)
{
	int	img_w;
	int	img_h;

	if (data->animations <= 250)
	{
		mlx_destroy_image(data->mlx, data->map->coin);
		data->map->coin = mlx_xpm_file_to_image(data->mlx,
				"./textures/money.xpm", &img_w, &img_h);
		mlx_put_image_to_window(data->mlx, data->win,
			data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
	}
	else if (data->animations > 250 && data->animations <= 500)
	{
		mlx_destroy_image(data->mlx, data->map->coin);
		data->map->coin = mlx_xpm_file_to_image(data->mlx,
				"./textures/coin1.xpm", &img_w, &img_h);
		mlx_put_image_to_window(data->mlx, data->win,
			data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
	}
	else
		ft_anim_2(data);
}

void	ft_coin_anim(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H) - 3)
	{
		if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_anim_1(data);
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
