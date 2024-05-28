/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:06:23 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/18 18:55:58 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"

void	free_exit(t_data *data, int f, char *message)
{
	int	i;

	i = 0;
	if (f == 1)
	{
		while (i < data->m_height)
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
	free(data->map1);
	ft_printf("%s\n", message);
	exit(1);
}

void	exit_err(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

void	map_name_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b' || str[i - 3] != '.')
	{
		write(1, "Error\nInvalid Filename\n", 23);
		exit(1);
	}
}

int	mlx_exit(t_data *data, char *str)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->bground)
		mlx_destroy_image(data->mlx, data->bground);
	return (free_exit(data, 1, str), 1);
}

int	close_window(t_data *data)
{
	mlx_exit(data, "Window closed.");
	return (0);
}
