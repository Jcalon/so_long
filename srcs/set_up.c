/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:23:32 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/03 17:27:32 by jcalon           ###   ########.fr       */
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
		if (buffer[0] != '\n')
			data->size_x += 1;
		else
			break ;
	}
	data->size_y = ft_lines(fd, data->size_x);
	data->size_y *= IMG_H;
	data->size_x *= IMG_W;
	close(fd);
}

static void	set_textures(t_data *data)
{
	char	*texture_path;
	int		img_w;
	int		img_h;

	texture_path = "./textures/bonhomme.xpm";
	data->img->player_up = mlx_xpm_file_to_image(data->mlx, texture_path, &img_w, &img_h);
	data->img->player_down = mlx_xpm_file_to_image(data->mlx, texture_path, &img_w, &img_h);
	data->img->player_left = mlx_xpm_file_to_image(data->mlx, texture_path, &img_w, &img_h);
	data->img->player_right = mlx_xpm_file_to_image(data->mlx, texture_path, &img_w, &img_h);
	texture_path = "./textures/ground.xpm";
	data->img->background = mlx_xpm_file_to_image(data->mlx, texture_path, &img_w, &img_h);
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
	data->collected = 0;
	data->map->money = 0;
	set_textures(data);
}