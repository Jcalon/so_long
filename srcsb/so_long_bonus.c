/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:32:28 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:47:46 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	basic_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

static int	ft_key(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == W)
		ft_move(data, 'y', UP);
	else if (keycode == A)
		ft_move(data, 'x', LEFT);
	else if (keycode == S)
		ft_move(data, 'y', DOWN);
	else if (keycode == D)
		ft_move(data, 'x', RIGHT);
	return (0);
}

static int	animations(t_data *data)
{
	if (data->animations >= 1000)
		data->animations = 0;
	data->animations++;
	if (data->collected != data->map->money)
		ft_coin_anim(data);
	else
		ft_home(data);
	if (data->map->map[data->p_y][data->p_x] == 'H'
		|| data->map->map[data->p_y][data->p_x] == 'V')
		ft_end(data, 2, "GAME OVER, you died...");
	return (0);
}

static void	ft_render_next_frame(t_data *data)
{
	ft_put_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_close, data);
	mlx_hook(data->win, 02, 1L << 0, ft_key, data);
	mlx_loop_hook(data->mlx, animations, data);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	t_data	data;

	if (argc != 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))
		!= (argv[1] + ft_strlen(argv[1]) - 4))
		basic_error("Error, write : ./so_long MAP.ber");
	ft_win_dim(&data, argv);
	if (data.size_x == 0 || data.size_y <= (4 * IMG_H))
		basic_error("Map dimension error");
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		ft_perror("Malloc error");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			data.size_x, data.size_y, "./so_long");
	struct_init(&data, &map);
	parse_map(&data, argv);
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	return (0);
}
