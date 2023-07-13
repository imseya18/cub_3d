/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:05:14 by loculy            #+#    #+#             */
/*   Updated: 2023/07/11 14:15:31 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_size(char **map)
{
	int	size;
	int	y;
	int	x;

	y = 0;
	size = 0;
	if (!map)
		return (0);
	while (map[y] && map[y] != 0)
	{
		x = 0;
		while (map[y] != 0 && map[y][x] != 0 && map[y][x] != '\n')
		{
			size++;
			x++;
		}
		y++;
	}
	return (size);
}

int	get_map_hitbox_size(char **map, char c)
{
	int	size;
	int	y;
	int	x;

	y = 0;
	size = 0;
	if (!map)
		return (0);
	while (map[y] && map[y] != 0)
	{
		x = 0;
		while (map[y] != 0 && map[y][x] != 0 && map[y][x] != '\n')
		{
			if (map[y][x] == c)
				size++;
			x++;
		}
		y++;
	}
	return (size);
}

t_coor	get_map_maxsize(char **map)
{
	t_coor	size;

	size.y = 0;
	size.x = 0;
	if (!map)
		return (size);
	while (map[size.y] && map[size.y] != 0)
	{
		if (ft_strlen_(map[size.y]) > size.x)
			size.x = ft_strlen_(map[size.y]);
		size.y++;
	}
	return (size);
}

t_main	*get_main(void *input)
{
	static t_main	*main;

	if (input != 0)
	{
		main = (t_main *)input;
	}
	return (main);
}

void	display_ground_sky(t_main *main)
{
	t_map	*map;
	int		i;

	map = main->map;
	i = -1;
	map->ground_sky = ftm_malloc(2 * sizeof(mlx_image_t));
	while (++i < 2)
	{
		map->ground_sky[i] = mlx_new_image(main->mlx, WIDTH, HEIGHT / 2);
		mlx_image_to_window(main->mlx, map->ground_sky[i], 0, i * (HEIGHT / 2));
	}
	fill_color_image(map->ground_sky[1], ft_pixel(ft_atoi(main->text->c[0]),
			ft_atoi(main->text->c[1]), ft_atoi(main->text->c[2]), 255));
	fill_color_image(map->ground_sky[0], ft_pixel(ft_atoi(main->text->f[0]),
			ft_atoi(main->text->f[1]), ft_atoi(main->text->f[2]), 255));
}
