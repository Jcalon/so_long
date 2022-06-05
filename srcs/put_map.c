/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:09 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 13:23:50 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_bonhomme_anim(t_data *data)
// {
// 	if (data->animations < 25000)
// 		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, data->p_x * IMG_W, data->p_y * IMG_H);
// 	else
// 		mlx_put_image_to_window(data->mlx, data->win, data->img->background, data->p_x * IMG_W, data->p_y * IMG_H);
// }

static void	ft_put_bonhomme(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, data->p_x * IMG_W, data->p_y * IMG_H);

}

static void	ft_put_stuff(t_data *data, char c)
{
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->map->home, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == (data->size_y / IMG_H) - 1 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rbcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == (data->size_y / IMG_H) - 1 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->lbcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == 0 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rtcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == 0 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->ltcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->top, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->left, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->right, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1' && data->map->y == (data->size_y / IMG_H) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->map->hole, (data->map->x * IMG_W), (data->map->y * IMG_H));
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
	ft_put_background(data);
	while (data->map->y < (data->size_y / IMG_H))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_bonhomme(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_stuff(data, '1');
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			ft_put_stuff(data, 'C');
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			ft_put_stuff(data, 'E');
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}