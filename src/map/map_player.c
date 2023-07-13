/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:43:19 by loculy            #+#    #+#             */
/*   Updated: 2023/06/21 18:10:40 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	orientation_to_angle(char orientation)
{
	if (orientation == 'N')
		return (90);
	else if (orientation == 'E')
		return (0);
	else if (orientation == 'S')
		return (270);
	else if (orientation == 'W')
		return (180);
	return (0);
}

t_player	set_player(int x, int y, int orientation)
{
	t_player	player;

	player.x = x;
	player.y = y;
	player.direc = orientation;
	return (player);
}

t_map	init_map_player(t_map map)
{
	int	x;
	int	y;

	y = 0;
	if (!map.map)
		return (map);
	while (map.map[y] && map.map[y] != 0)
	{
		x = 0;
		while (map.map[y] != 0 && map.map[y][x] != 0 && map.map[y][x] != '\n')
		{
			if (map.map[y][x] == 'N' || map.map[y][x] == 'S'
				|| map.map[y][x] == 'E' || map.map[y][x] == 'W')
			{
				map.start = set_player(x * MAP_RES + (MAP_RES / 4),
						y * MAP_RES + (MAP_RES / 4),
						orientation_to_angle(map.map[y][x]));
				map.current = map.start;
				return (map);
			}
			x++;
		}
		y++;
	}
	return (map);
}
