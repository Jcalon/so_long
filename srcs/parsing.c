/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:17:36 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/05 19:53:10 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	testmap(int e, int p, t_data *data)
{
	if (e < 1)
		exit(EXIT_FAILURE);
	if (data->map->money < 1)
		exit(EXIT_FAILURE);
	if (p != 1)
		exit(EXIT_FAILURE);
}

static void	check_map(t_data *data)
{
	int	ep[2];
	int	x;
	int	y;

	y = 0;
	ep[0] = 0;
	ep[1] = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == 'C')
				data->map->money++;
			if (data->map->map[y][x] == 'E')
				ep[0]++;
			if (data->map->map[y][x] == 'P')
				ep[1]++;
			if (ft_cmp(data->map->map[y][x], "CEP01HV") == 1)
				exit(EXIT_FAILURE);
			x++;
		}
		y++;
	}
	testmap(ep[0], ep[1], data);
}

static void	check_small(t_data *data)
{
	if (data->map->map[0][0] != '1')
		exit(EXIT_FAILURE);
	else if (data->map->map[0][(data->size_x / IMG_W) - 1] != '1')
		exit(EXIT_FAILURE);
}

static void	check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[0][x] != '1')
				exit(EXIT_FAILURE);
			else if (data->map->map[y][0] != '1')
				exit(EXIT_FAILURE);
			else if (data->map->map[y][(data->size_x / IMG_W) - 1] != '1')
				exit(EXIT_FAILURE);
			else if (data->map->map[(data->size_y / IMG_H) - 4][x] != '1')
				exit(EXIT_FAILURE);
			else
				x++;
		}
		y++;
	}
}

void	parse_map(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;

	if (argc != 2)
		exit(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	while (1)
	{
		data->map->map[i] = get_next_line(fd);
		if (!data->map->map[i])
			break ;
		data->map->map[i][(data->size_x / IMG_W)] = '\0';
		i++;
	}
	check_map(data);
	if ((data->size_y / IMG_W) - 3 != 1)
		check_borders(data);
	else
		check_small(data);
	close(fd);
}
