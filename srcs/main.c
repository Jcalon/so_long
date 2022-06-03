/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:32:28 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/03 16:45:55 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

static int ft_key(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_end(data);
	else if (keycode == W)
		ft_move(data, 'y', UP);
	else if (keycode == A)
		ft_move(data, 'x', LEFT);
	else if (keycode == S)
		ft_move(data, 'y', DOWN);
	else if (keycode == D)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_end(data);
	return (0);
}

static void	ft_render_next_frame(t_data *data)
{
	ft_put_background(data);
	ft_put_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_end, data);
	mlx_key_hook(data->win, ft_key, data);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;
	
	ft_win_dim(&data, argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		exit(EXIT_FAILURE);
	data.mlx = mlx_init();
	struct_init(&data, &map);
	parse_map(&data, argv, argc);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "./so_long");
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	exit(EXIT_FAILURE);
	return (0);
}