/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mechant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:11:27 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 20:21:45 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_move_mechant(t_data *data)
// {
// 	int	img_w;
// 	int	img_h;

// 	data->map->x = 0;
// 	data->map->y = 0;
// 	while (data->map->y < (data->size_y / IMG_H) - 3)
// 	{
// 		if (data->map->map[data->map->y][data->map->x] == 'F')
// 		{
// 			if (data->animations <= 500 && data->map->map[data->map->y][data->map->x] != '1'
// 			&& data->map->map[data->p_y + 1 * dir][data->p_x] != 'E')
// 			{
// 				mlx_put_image_to_window(data->mlx, data->win,
// 					data->img->background, data->map->y * IMG_W, data->map->x * IMG_H);
// 				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
// 			}
// 			else if (data->animations <= 1000)
// 			{

// 				mlx_put_image_to_window(data->mlx, data->win, data->map->coin, (data->map->x * IMG_W), (data->map->y * IMG_H));
// 			}
// 		}
// 		if (data->map->x < (data->size_x / IMG_W))
// 			data->map->x++;
// 		else
// 		{
// 			data->map->y++;
// 			data->map->x = 0;
// 		}
// 	}
// }
