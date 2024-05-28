/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:06:06 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/18 18:52:25 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

int	render(t_data *data)
{
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		data->px * PIXEL, data->py * PIXEL);
	return (0);
}

int	map_validation(t_data *data)
{
	if (data->cc == 0 || data->ec != 1 || data->pc != 1)
		return (0);
	if (data->nl_check != 0)
		return (0);
	get_mwh_pxy(data, data->map2);
	if (data->c_check != 0 || data->width_check != 0)
		return (0);
	data->w_check = wall_check(data->map2, data->m_width, data->m_height);
	if (!data->w_check)
		return (0);
	data->p_check = flood_fill(data, -1);
	if (!data->p_check)
		return (0);
	else
		return (1);
}

void	start_data(t_data *data, char *map_name)
{
	data->cc = 0;
	data->ec = 0;
	data->pc = 0;
	data->mc = 0;
	data->nl_check = 0;
	data->c_check = 0;
	data->m_width = 0;
	data->m_height = 0;
	if (!(file_len(data, map_name)))
		exit_err("Error");
	data->map1t = (char *)malloc(sizeof(char) * data->len);
	if (!data->map1t)
		exit_err("Error");
	if (!read_map(data, map_name, -1, -1))
		free_exit(data, 0, "Error");
	data->map2 = ft_split(data->map1, '\n');
	if (!data->map2)
		free_exit(data, 0, "Error\nMap2 malloc");
	if (!map_validation(data))
		free_exit(data, 1, "Error\nInvalid Map");
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		map_name_check(av[1]);
		start_data(&data, av[1]);
		data.mlx = mlx_init();
		if (!data.mlx)
			free_exit(&data, 1, "Error\n");
		data.win = mlx_new_window(data.mlx, data.m_width * PIXEL,
				data.m_height * PIXEL, "so_long");
		if (!data.win)
			free_exit(&data, 1, "Error\n");
		load_textures(&data);
		mlx_hook(data.win, 2, 0, keyboard, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop_hook(data.mlx, render, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		write(1, "Error\nInvalid argument number\n", 30);
		exit(1);
	}
	return (0);
}
