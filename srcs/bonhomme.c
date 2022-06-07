/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonhomme_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:02:54 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 12:24:10 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_coin(t_data *data)
{
	if (data->map->map[data->p_y][data->p_x] == 'C')
	{
		++data->collected;
		data->map->map[data->p_y][data->p_x] = '0';
	}
	if (data->map->map[data->p_y][data->p_x] == 'E' )
		ft_end(data, 1, NULL);
}

static void	ft_move_bonhomme(t_data *data, char p, int dir)
{
	if (p == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->player_down, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->player_up, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->player_left, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->player_right, (data->p_x * IMG_W), (data->p_y * IMG_H));
	data->counter++;
	ft_printf("%d meters done so far !\n", data->counter);
	ft_coin(data);
}

static void	ft_test_end(t_data *data, char p, int dir)
{
	if (p == 'x' && data->map->map[data->p_y][data->p_x + dir] == 'E'
			&& data->collected == data->map->money)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_x = data->p_x + dir;
		ft_move_bonhomme(data, p, dir);
	}
	else if (p == 'y' && data->map->map[data->p_y + dir][data->p_x] == 'E'
			&& data->collected == data->map->money)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_y = data->p_y + dir;
		ft_move_bonhomme(data, p, dir);
	}
}

void	ft_move(t_data *data, char p, int dir)
{
	if (p == 'y' && data->map->map[data->p_y + dir][data->p_x] != '1'
			&& data->map->map[data->p_y + dir][data->p_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_y = data->p_y + dir;
		ft_move_bonhomme(data, p, dir);
	}
	else if (p == 'x' && data->map->map[data->p_y][data->p_x + dir] != '1'
			&& data->map->map[data->p_y][data->p_x + dir] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_x = data->p_x + dir;
		ft_move_bonhomme(data, p, dir);
	}
	else
		ft_test_end(data, p, dir);
}
