/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:05:52 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/18 18:48:14 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

int	file_len(t_data *data, char *map_name)
{
	char	c;
	int		fd;
	int		ret;
	int		length;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = 1;
	length = 0;
	while (ret > 0)
	{
		ret = read(fd, &c, 1);
		if (ret < 0)
			return (0);
		length += ret;
	}
	data->len = length;
	close(fd);
	return (1);
}

int	read_map(t_data *data, char *map_name, int i, int fd)
{
	fd = open(map_name, O_RDONLY);
	if (fd < 0 || read(fd, data->map1t, data->len) == -1)
	{
		free(data->map1t);
		return (0);
	}
	data->map1t[data->len] = '\0';
	close(fd);
	trim_map(data);
	free(data->map1t);
	if (!data->map1)
		return (0);
	while (data->map1[++i])
	{
		if (data->map1[i] == 'C')
			data->cc++;
		else if (data->map1[i] == 'E')
			data->ec++;
		else if (data->map1[i] == 'P')
			data->pc++;
		if (data->map1[i] == '\n' && data->map1[i + 1] == '\n')
			data->nl_check++;
	}
	return (1);
}

void	trim_map(t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = data->len - 1;
	while (data->map1t[i] != '\0' && data->map1t[i] == '\n')
		i++;
	while (data->map1t[j] != '\0' && data->map1t[j] == '\n')
		j--;
	len = j - i;
	data->map1 = (char *)malloc(sizeof(char) * (len));
	if (!data->map1)
		return ;
	while (len >= 0)
	{
		data->map1[len] = data->map1t[j];
		len--;
		j--;
	}
}

void	get_mwh_pxy(t_data *data, char **map)
{
	int	i;
	int	j;

	data->m_width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != '0' && map[i][j] != '1')
				data->c_check++;
			if (map[i][j] == 'P')
			{
				data->px = j;
				data->py = i;
			}
		}
		if (j != data->m_width)
			data->width_check++;
	}
	data->m_height = i;
}

int	wall_check(char **map2, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < x)
	{
		if (map2[0][j] != '1' || map2[y - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < y)
	{
		if (map2[i][0] != '1' || map2[i][x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
