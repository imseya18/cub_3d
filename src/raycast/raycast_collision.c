/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:11:30 by loculy            #+#    #+#             */
/*   Updated: 2023/07/05 16:10:26 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_ray_collision(double x, double y, t_coor wall)
{
	if ((x >= (double)wall.x && x <= (double)wall.x + MAP_RES
			&& (y == (double)wall.y + MAP_RES))
		|| (x >= (double)wall.x && x <= (double)wall.x + MAP_RES
			&& (y == (double)wall.y))
		|| (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
			&& (x == (double)wall.x + MAP_RES))
		|| (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
			&& (x == (double)wall.x)))
	{
		return (1);
	}
	return (0);
}

int	raycast_get_collision(t_dblcoor n_coor, t_main *main)
{
	int		i;
	t_map	*map;

	i = 0;
	map = main->map;
	while (i < map->wall_size)
	{
		if (is_ray_collision(n_coor.x, n_coor.y, map->wall[i]) == 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < map->door_size)
	{
		if (map->door[i].open == 0
			&& is_ray_collision(n_coor.x, n_coor.y, map->door[i].coor) == 1)
			return (1);
		i++;
	}
	return (0);
}
