/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:02:54 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/03 17:37:07 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_bonhomme(t_data *data, char p, int dir)
{
	if (p == 'y' && dir == UP)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'y' && dir == DOWN)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'x' && dir == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, (data->p_x * IMG_W), (data->p_y * IMG_H));
	else if (p == 'x' && dir == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->player_up, (data->p_x * IMG_W), (data->p_y * IMG_H));
	++data->counter;
	ft_printf("%d moove/moves made !\n", data->counter);
	if (data->map->map[data->p_y][data->p_x] == 'C')
	{
		++data->collected;
		data->map->map[data->p_y][data->p_x] = '0';
	}
}

void	ft_move(t_data *data, char p, int dir)
{
	if (p == 'y' && data->map->map[data->p_y + (1 * dir)][data->p_x] != '1' && data->map->map[data->p_y + 1 * dir][data->p_x] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_y = data->p_y + (1 * dir);
		ft_move_bonhomme(data, p, dir);
	}
	else if (p == 'x' && data->map->map[data->p_y][data->p_x + (1 * dir)] != '1' && data->map->map[data->p_y][data->p_x + (1 * dir)] != 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->background, (data->p_x * IMG_W), (data->p_y * IMG_H));
		data->p_x = data->p_x + (1 * dir);
		ft_move_bonhomme(data, p, dir);
	}
	else if (p == 'x' && data->map->map[data->p_y][data->p_x + (1 * dir)] == 'E' && data->collected == data->map->money)
		data->p_x = data->p_x + (1 * dir);
	else if (p == 'y' && data->map->map[data->p_y + (1 * dir)][data->p_x] == 'E' && data->collected == data->map->money)
		data->p_y = data->p_y + (1 * dir);
	mlx_do_sync(data->mlx);
}