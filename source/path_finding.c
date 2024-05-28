/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:05:59 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/06 12:05:59 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

static void	free_map(char **map2, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map2[i]);
		i++;
	}
	free(map2);
}

static char	*copy_line(char *str)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

static int	check_movement(t_data *data, size_t y, size_t x)
{
	if (data->map2[y][x] == '1')
		return (0);
	if (data->map2[y][x] == 'C')
		data->cc--;
	if (data->map2[y][x] == 'E')
		data->ec--;
	data->map2[y][x] = '1';
	if (check_movement(data, y + 1, x))
		return (1);
	if (check_movement(data, y - 1, x))
		return (1);
	if (check_movement(data, y, x + 1))
		return (1);
	if (check_movement(data, y, x - 1))
		return (1);
	return (0);
}

int	flood_fill(t_data *data, int i)
{
	t_data	temp;

	temp.cc = data->cc;
	temp.px = data->px;
	temp.py = data->py;
	temp.ec = data->ec;
	temp.map2 = (char **)malloc(data->m_height * sizeof(char *));
	if (!temp.map2)
		return (0);
	while (++i < data->m_height)
	{
		temp.map2[i] = copy_line(data->map2[i]);
		if (!temp.map2[i])
		{
			free_map(temp.map2, (i));
			return (0);
		}
	}
	check_movement(&temp, temp.py, temp.px);
	free_map(temp.map2, data->m_height);
	if (!(temp.ec == 0 && temp.cc == 0))
		return (0);
	return (1);
}
