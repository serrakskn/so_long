/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:06:04 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/12 00:37:58 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

void	load_textures(t_data *data)
{
	int	x;
	int	y;

	data->player = mlx_xpm_file_to_image(data->mlx,
			"textures/player.xpm", &y, &x);
	data->coin = mlx_xpm_file_to_image(data->mlx, "textures/coin.xpm", &y, &x);
	data->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &y, &x);
	data->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &y, &x);
	data->bground = mlx_xpm_file_to_image(data->mlx,
			"textures/bground.xpm", &y, &x);
	if (!data->player || !data->coin || !data->exit
		|| !data->wall || !data->bground || !data->mlx || !data->win)
		mlx_exit(data, "Error\nTextures couldn't load");
}

int	keyboard(int keycode, t_data *data)
{
	if (keycode == ESC)
		mlx_exit(data, "Window closed.");
	else if (keycode == W && data->map2[data->py - 1][data->px] != '1')
		data->py--;
	else if (keycode == A && data->map2[data->py][data->px - 1] != '1')
		data->px--;
	else if (keycode == S && data->map2[data->py + 1][data->px] != '1')
		data->py++;
	else if (keycode == D && data->map2[data->py][data->px + 1] != '1')
		data->px++;
	else
		return (0);
	ft_printf("Moves: %d\n", ++data->mc);
	if (data->map2[data->py][data->px] == 'C')
	{
		data->cc--;
		data->map2[data->py][data->px] = '0';
	}
	if (data->map2[data->py][data->px] == 'E' && data->cc == 0)
		mlx_exit(data, "You won!");
	return (0);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < data->m_height)
	{
		x = -1;
		while (++x < data->m_width)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->bground, x * PIXEL, y * PIXEL);
			if (data->map2[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall, x * PIXEL, y * PIXEL);
			else if (data->map2[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit, x * PIXEL, y * PIXEL);
			else if (data->map2[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->coin, x * PIXEL, y * PIXEL);
		}
	}
}
