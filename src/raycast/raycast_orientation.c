/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_orientation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:56:29 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 17:17:06 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*2:SUD | 1:NORTH | 4:WEST | 3:EST */
int	get_hit_orient(double x, double y, t_coor wall)
{
	if (x >= (double)wall.x && x <= (double)wall.x + MAP_RES
		&& (y == (double)wall.y + MAP_RES))
		return (2);
	if (x >= (double)wall.x && x <= (double)wall.x + MAP_RES
		&& (y == (double)wall.y))
		return (1);
	if (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
		&& (x == (double)wall.x + MAP_RES))
		return (4);
	if (y >= (double)wall.y && y <= (double)wall.y + MAP_RES
		&& (x == (double)wall.x))
		return (3);
	return (0);
}

t_hit	get_hit_texture_pose(double x, double y, t_hit out, t_coor wall)
{
	out.orientation = get_hit_orient(x, y, wall);
	if (out.orientation == 1)
		out.pixel_col = MAP_RES - (int)(x - wall.x);
	if (out.orientation == 2)
		out.pixel_col = (int)(x - wall.x);
	if (out.orientation == 3)
		out.pixel_col = (int)(y - wall.y);
	if (out.orientation == 4)
		out.pixel_col = MAP_RES - (int)(y - wall.y);
	return (out);
}

t_hit	get_hit_texture_box(t_main *main, t_dblcoor val)
{
	int		i;
	t_hit	box;
	t_map	*map;

	map = main->map;
	box.orientation = 0;
	box.hit_type = 1;
	i = -1;
	while (++i < map->wall_size)
	{
		if (is_ray_collision(val.x, val.y, map->wall[i]) == 1)
			return (get_hit_texture_pose(val.x, val.y, box, map->wall[i]));
	}
	box.hit_type = 2;
	i = -1;
	while (++i < map->door_size)
	{
		if (map->door[i].open == 0
			&& is_ray_collision(val.x, val.y, map->door[i].coor) == 1)
			return (get_hit_texture_pose(val.x, val.y, box, map->door[i].coor));
	}
	return (box);
}

int	get_hit_texture_spbox(t_main *main, t_dblcoor val)
{
	int		i;
	t_map	*map;

	i = 0;
	map = main->map;
	while (i < map->wall_size)
	{
		if (is_ray_collision(val.x, val.y, map->wall[i]) == 1)
		{
			return (get_hit_orient(val.x, val.y, map->wall[i]));
		}
		i++;
	}
	return (0);
}
