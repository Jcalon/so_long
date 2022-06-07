/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:17:36 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/07 13:42:50 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	testmap(int e, int p, t_data *data)
{
	if (e < 1)
		ft_end(data, 2, "Map error : No exit");
	if (data->map->money < 1)
		ft_end(data, 2, "Map error : No coin");
	if (p != 1)
		ft_end(data, 2, "Map error : Invalid number of player spawn");
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
				ft_end(data, 2, "Map error : Invalid letter");
			x++;
		}
		y++;
	}
	testmap(ep[0], ep[1], data);
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
				ft_end(data, 2, "Map error : Border");
			else if (data->map->map[y][0] != '1')
				ft_end(data, 2, "Map error : Border");
			else if (data->map->map[y][(data->size_x / IMG_W) - 1] != '1')
				ft_end(data, 2, "Map error : Border");
			else if (data->map->map[(data->size_y / IMG_H) - 4][x] != '1')
				ft_end(data, 2, "Map error : Border");
			else
				x++;
		}
		y++;
	}
}

void	parse_map(t_data *data, char **argv)
{
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_end(data, 0, "Open map error");
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
	check_borders(data);
	close(fd);
}
