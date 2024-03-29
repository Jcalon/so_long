/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:29:24 by crazyd            #+#    #+#             */
/*   Updated: 2022/06/07 12:33:47 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_more_stuff(t_data *data)
{
	if (data->map->y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->top,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->left,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->right,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->map->hole,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_stuff(t_data *data)
{
	if ((data->size_y / IMG_H) == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bottom, data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->map->y == (data->size_y / IMG_H) - 1
		&& data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rbcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 1 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->lbcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rtcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->ltcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else
		ft_put_more_stuff(data);
}
