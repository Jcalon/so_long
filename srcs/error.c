/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:08:20 by crazyd            #+#    #+#             */
/*   Updated: 2022/06/06 22:09:56 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	niel(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

static void	ft_destroy_img(t_data *data)
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
}

int	ft_end(t_data *data, int win, char *str)
{
	ft_destroy_img(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->img);
	niel(data->map->map);
	if (win == 1)
	{
		ft_printf("You walked %d meters to get the %d coins ! GG\n",
			data->counter, data->collected);
		exit(EXIT_SUCCESS);
	}
	else if (win == 2)
	{
		ft_printf("%s\n", str);
		exit(EXIT_SUCCESS);
	}
	else
		ft_perror(str);
	return (0);
}

int	ft_close(t_data *data)
{
	ft_end(data, 2, "Too hard for you ?");
	return (0);
}
