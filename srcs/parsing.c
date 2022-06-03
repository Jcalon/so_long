/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:17:36 by jcalon            #+#    #+#             */
/*   Updated: 2022/06/03 17:46:40 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_cmp(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			break ;
		str++;
	}
	if (*str)
		return (0);
	return (1);
}

static void	testmap(int e, int p, t_data *data)
{
	if (e < 1)
		exit(EXIT_FAILURE);
	if (data->map->money < 1)
		exit(EXIT_FAILURE);
	if (p != 1)
		exit(EXIT_FAILURE);
}

static void check_map(t_data *data)
{
	int	e;
	int	p;
	int	x;
	int	y;

	y = 0;
	e = 0;
	p = 0;
	while (data->map->map[y] != NULL)
	{
		x = 0;
		while (data->map->map[y][x] != '\0')
		{
			if (data->map->map[y][x] == 'C')
				data->map->money++;
			if (data->map->map[y][x] == 'E')
				e++;
			if (data->map->map[y][x] == 'P')
				p++;
			if (ft_cmp(data->map->map[y][x], "CEP01") == 1)
				exit(EXIT_FAILURE);
			x++;
		}
		y++;
	}
	testmap(e, p, data);
}

void	parse_map(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	
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
	//check borders;
	(void)argc;
	close(fd);
}