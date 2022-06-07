/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stuff_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:29:24 by crazyd            #+#    #+#             */
/*   Updated: 2022/06/07 13:42:58 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (data->map->y == (data->size_y / IMG_H) - 4)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->map->hole,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_stuff(t_data *data)
{
	if ((data->size_y / IMG_H) - 3 == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->bottom, data->map->x * IMG_W, data->map->y * IMG_H);
	else if (data->map->y == (data->size_y / IMG_H) - 4
		&& data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rbcorner,
			(data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 4 && data->map->x == 0)
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

void	ft_home(t_data *data)
{
	int	img_w;
	int	img_h;

	data->map->x = 0;
	data->map->y = 0;
	mlx_destroy_image(data->mlx, data->map->home);
	while (data->map->y < (data->size_y / IMG_H) - 3)
	{
		if (data->map->map[data->map->y][data->map->x] == 'E')
		{
			data->map->home = mlx_xpm_file_to_image(data->mlx,
					"./textures/homeopen.xpm", &img_w, &img_h);
			mlx_put_image_to_window(data->mlx, data->win, data->map->home,
				(data->map->x * IMG_W), (data->map->y * IMG_H));
		}
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
