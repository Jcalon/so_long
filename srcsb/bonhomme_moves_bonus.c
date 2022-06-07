/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonhomme_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:02:54 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:42:22 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	ft_text(t_data *data)
{
	char	*count;
	char	*txt;

	data->counter++;
	count = ft_itoa(data->counter);
	if (!count)
		ft_end(data, 0, "Malloc error");
	txt = ft_strjoin(count, " meters done so far !");
	if (!txt)
	{
		free(count);
		ft_end(data, 0, "Malloc error");
	}
	ft_put_bottom(data);
	mlx_string_put(data->mlx, data->win,
		(data->size_x / 2) - IMG_W - ft_strlen(txt),
		data->size_y - (2 * IMG_H) + 15, 0, txt);
	free(txt);
	free(count);
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
	ft_text(data);
	ft_coin(data);
	ft_move_mechant_horizontal(data);
	ft_move_mechant_vertical(data);
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
