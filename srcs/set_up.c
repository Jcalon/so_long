/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:23:32 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 20:01:39 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_lines(int fd, int x)
{
	int		count;
	char	*lines;

	count = 1;
	while (1)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		if ((int)ft_strlen(lines) < x / IMG_W
			|| ((int)ft_strlen(lines) == 1 && *lines != '\n'))
		{
			free(lines);
			exit(EXIT_FAILURE);
		}
		else
		{
			free(lines);
			count++;
		}
	}
	return (count);
}

void	ft_win_dim(t_data *data, char **argv)
{
	int		fd;
	int		rbytes;
	char	buffer[2];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	rbytes = 1;
	data->size_x = 0;
	while (rbytes == 1)
	{
		rbytes = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (buffer[0] != '\n' && rbytes == 1)
			data->size_x += 1;
		else
			break ;
	}
	data->size_y = ft_lines(fd, data->size_x) + 3;
	data->size_y *= IMG_H;
	data->size_x *= IMG_W;
	close(fd);
}

static void	set_more_textures(t_data *data)
{
	int		img_w;
	int		img_h;

	data->img->rtcorner = mlx_xpm_file_to_image(data->mlx,
			"./textures/toprightcorner.xpm", &img_w, &img_h);
	data->img->ltcorner = mlx_xpm_file_to_image(data->mlx,
			"./textures/topleftcorner.xpm", &img_w, &img_h);
	data->img->rbcorner = mlx_xpm_file_to_image(data->mlx,
			"./textures/bottomrightcorner.xpm", &img_w, &img_h);
	data->img->lbcorner = mlx_xpm_file_to_image(data->mlx,
			"./textures/bottomleftcorner.xpm", &img_w, &img_h);
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"./textures/ground.xpm", &img_w, &img_h);
	data->img->top = mlx_xpm_file_to_image(data->mlx,
			"./textures/topvoid.xpm", &img_w, &img_h);
	data->img->bad_up = mlx_xpm_file_to_image(data->mlx,
			"./textures/mechantfront.xpm", &img_w, &img_h);
	data->img->bad_down = mlx_xpm_file_to_image(data->mlx,
			"./textures/mechantback.xpm", &img_w, &img_h);
	data->img->bad_left = mlx_xpm_file_to_image(data->mlx,
			"./textures/mechantleft.xpm", &img_w, &img_h);
	data->img->bad_right = mlx_xpm_file_to_image(data->mlx,
			"./textures/mechantright.xpm", &img_w, &img_h);
}

static void	set_textures(t_data *data)
{
	int		img_w;
	int		img_h;

	data->img->player_up = mlx_xpm_file_to_image(data->mlx,
			"./textures/bonhomme.xpm", &img_w, &img_h);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx,
			"./textures/bonhommeback.xpm", &img_w, &img_h);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx,
			"./textures/bonhommeleft.xpm", &img_w, &img_h);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx,
			"./textures/bonhommeright.xpm", &img_w, &img_h);
	data->img->bottom = mlx_xpm_file_to_image(data->mlx,
			"./textures/bottomvoid.xpm", &img_w, &img_h);
	data->img->left = mlx_xpm_file_to_image(data->mlx,
			"./textures/leftvoid.xpm", &img_w, &img_h);
	data->img->right = mlx_xpm_file_to_image(data->mlx,
			"./textures/rightvoid.xpm", &img_w, &img_h);
	data->map->coin = mlx_xpm_file_to_image(data->mlx,
			"./textures/money.xpm", &img_w, &img_h);
	data->map->home = mlx_xpm_file_to_image(data->mlx,
			"./textures/home.xpm", &img_w, &img_h);
	data->map->hole = mlx_xpm_file_to_image(data->mlx,
			"./textures/void.xpm", &img_w, &img_h);
	set_more_textures(data);
}

void	struct_init(t_data *data, t_map *map)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		exit (EXIT_FAILURE);
	data->map = map;
	data->img = img;
	data->counter = 0;
	data->animations = 0;
	data->collected = 0;
	data->map->money = 0;
	set_textures(data);
}
