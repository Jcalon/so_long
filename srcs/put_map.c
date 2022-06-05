/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:15:09 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 19:58:18 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coin_anim(t_data *data)
{
	int	img_w;
	int	img_h;

	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->size_y / IMG_H) - 3)
	{
		if (data->map->map[data->map->y][data->map->x] == 'C')
		{
			if (data->animations <= 250)
			{
				mlx_destroy_image(data->mlx, data->map->coin);
				data->map->coin = mlx_xpm_file_to_image(data->mlx, "./textures/money.xpm", &img_w, &img_h);
				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
			}
			else if (data->animations > 250 && data->animations <= 500)
			{
				mlx_destroy_image(data->mlx, data->map->coin);
				data->map->coin = mlx_xpm_file_to_image(data->mlx, "./textures/coin1.xpm", &img_w, &img_h);
				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
			}
			else if (data->animations > 500 && data->animations <= 750)
			{
				mlx_destroy_image(data->mlx, data->map->coin);
				data->map->coin = mlx_xpm_file_to_image(data->mlx, "./textures/coin2.xpm", &img_w, &img_h);
				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
			}
			else if (data->animations <= 1000)
			{
				mlx_destroy_image(data->mlx, data->map->coin);
				data->map->coin = mlx_xpm_file_to_image(data->mlx, "./textures/coin3.xpm", &img_w, &img_h);
				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
			}
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
			data->map->home = mlx_xpm_file_to_image(data->mlx, "./textures/homeopen.xpm", &img_w, &img_h);
			mlx_put_image_to_window(data->mlx, data->win, data->map->home, (data->map->x * IMG_W), (data->map->y * IMG_H));
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

static void	ft_put_bonhomme(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, data->p_x * IMG_W, data->p_y * IMG_H);

}

static void	ft_put_stuff(t_data *data)
{
	if ((data->size_y / IMG_H) - 3 == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 4 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rbcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 4 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->lbcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->rtcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0 && data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->ltcorner, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->top, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->x == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img->left, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->x == (data->size_x / IMG_W) - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img->right, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else if (data->map->y == (data->size_y / IMG_H) - 4)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom, (data->map->x * IMG_W), (data->map->y * IMG_H));
	else
		mlx_put_image_to_window(data->mlx, data->win, data->map->hole, (data->map->x * IMG_W), (data->map->y * IMG_H));
}

void	ft_put_bottom(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->bottom, x, data->size_y - IMG_H);
		x += IMG_W;
	}
	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background, x, data->size_y - (2 * IMG_H));
		x += IMG_W;
	}
	x = 0;
	while (x < data->size_x)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->top, x, data->size_y - (3 * IMG_H));
		x += IMG_W;
	}
}

void	ft_put_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size_y - 3)
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
	ft_put_bottom(data);
	while (data->map->y < ((data->size_y - 3) / IMG_H) - 2)
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			ft_put_bonhomme(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			ft_put_stuff(data);
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->map->home, (data->map->x * IMG_W), (data->map->y * IMG_H));
		else if (data->map->map[data->map->y][data->map->x] == 'V')
			mlx_put_image_to_window(data->mlx, data->win, data->img->bad_up, (data->map->x * IMG_W), (data->map->y * IMG_H));
		else if (data->map->map[data->map->y][data->map->x] == 'H')
			mlx_put_image_to_window(data->mlx, data->win, data->img->bad_right, (data->map->x * IMG_W), (data->map->y * IMG_H));
		if (data->map->x < (data->size_x / IMG_W))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}