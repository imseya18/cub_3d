/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:30:02 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_mini_map_fill(t_main *main, int i, int x, int y)
{
	t_map	*map;

	map = main->map;
	map->img_bck[i] = mlx_new_image(main->mlx, MN_MAP_RES, MN_MAP_RES);
	if (!map->img_bck[i]
		|| (mlx_image_to_window(main->mlx, map->img_bck[i],
				x * MN_MAP_RES, y * MN_MAP_RES) < 0))
		exit(0);
	if (map->map[y][x] == '1')
		fill_color_image(map->img_bck[i], ft_pixel(255, 255, 255, 255));
	else if (map->map[y][x] == 'D')
		fill_color_image(map->img_bck[i], ft_pixel(125, 80, 50, 255));
	else if (map->map[y][x] != ' ' && map->map[y][x] != '\t')
		fill_color_image(map->img_bck[i], ft_pixel(50, 50, 50, 255));
	i++;
}

void	display_mini_map(t_main *main)
{
	t_map	*map;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	map = main->map;
	map->bck_size = get_map_size(map->map);
	map->img_bck = ftm_malloc((map->bck_size) * sizeof(mlx_image_t));
	while (map->map[y] != 0)
	{
		x = 0;
		while (map->map[y][x] != 0 && map->map[y][x] != '\n')
		{
			display_mini_map_fill(main, i, x, y);
			x++;
		}
		y++;
	}
}

void	display_mini_map_player(t_main *main)
{
	t_map	*map;

	map = main->map;
	map->img_player = ftm_malloc((1) * sizeof(mlx_image_t));
	map->img_player = mlx_new_image(main->mlx, MN_PLAYER_RES, MN_PLAYER_RES);
	if (!map->img_player || (mlx_image_to_window(main->mlx, map->img_player,
				map->start.x / 50, map->start.y / 50) < 0))
		exit(0);
	fill_color_image(map->img_player, ft_pixel(255, 0, 0, 255));
}
