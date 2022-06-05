/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:32:28 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 20:01:45 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void niel(char **str)
{
	int	i;
	
	i = 0;
	while(str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_end(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->background);
	mlx_destroy_image(data->mlx, data->img->player_down);
	mlx_destroy_image(data->mlx, data->img->player_left);
	mlx_destroy_image(data->mlx, data->img->player_right);
	mlx_destroy_image(data->mlx, data->img->player_up);
	mlx_destroy_image(data->mlx, data->img->bad_down);
	mlx_destroy_image(data->mlx, data->img->bad_left);
	mlx_destroy_image(data->mlx, data->img->bad_right);
	mlx_destroy_image(data->mlx, data->img->bad_up);
	mlx_destroy_image(data->mlx, data->img->left);
	mlx_destroy_image(data->mlx, data->img->top);
	mlx_destroy_image(data->mlx, data->img->bottom);
	mlx_destroy_image(data->mlx, data->img->right);
	mlx_destroy_image(data->mlx, data->img->lbcorner);
	mlx_destroy_image(data->mlx, data->img->ltcorner);
	mlx_destroy_image(data->mlx, data->img->rbcorner);
	mlx_destroy_image(data->mlx, data->img->rtcorner);
	mlx_destroy_image(data->mlx, data->map->coin);
	mlx_destroy_image(data->mlx, data->map->hole);
	mlx_destroy_image(data->mlx, data->map->home);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	niel(data->map->map);
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
	return (0);
}

static int animations(t_data *data)
{
	if (data->animations >= 1000)
		data->animations = 0;
	data->animations++;
	if (data->collected != data->map->money)
		ft_coin_anim(data);
	else
		ft_home(data);
	return (0);
}

static void	ft_render_next_frame(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->size_x, data->size_y, "./so_long");
	ft_put_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_end, data);
	mlx_hook(data->win, 02, 1L << 0, ft_key, data);
	mlx_loop_hook(data->mlx, animations, data);
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
	ft_render_next_frame(&data);
	mlx_loop(data.mlx);
	exit(EXIT_FAILURE);
	return (0);
}