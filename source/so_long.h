/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekeskin <sekeskin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:06:20 by sekeskin          #+#    #+#             */
/*   Updated: 2024/05/18 18:22:12 by sekeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 40
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct c_data
{
	char	**map2;
	char	*map1;
	char	*map1t;
	int		len;
	int		m_width;
	int		m_height;
	int		cc;
	int		ec;
	int		pc;
	int		mc;
	int		px;
	int		py;
	int		nl_check;
	int		c_check;
	int		width_check;
	int		w_check;
	int		p_check;
	void	*mlx;
	void	*win;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*bground;

}	t_data;

void	map_name_check(char *str);
void	trim_map(t_data *data);
void	get_mwh_pxy(t_data *data, char **map);
void	free_exit(t_data *data, int f, char *message);
void	load_textures(t_data *data);
void	exit_err(char *message);
void	render_map(t_data *data);
int		file_len(t_data *data, char *map_name);
int		read_map(t_data *data, char *map_name, int i, int fd);
int		wall_check(char **map2, int x, int y);
int		flood_fill(t_data *data, int i);
int		mlx_exit(t_data *data, char *str);
int		keyboard(int keycode, t_data *data);
int		close_window(t_data *data);

#endif