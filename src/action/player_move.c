/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:33:20 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:25:56 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_player(t_main *main, int x, int y)
{
	t_map	*map;

	map = main->map;
	map->current.y += y;
	map->current.x += x;
	map->img_player->instances[0].x = map->current.x / 50;
	map->img_player->instances[0].y = map->current.y / 50;
}

void	set_mv(t_main *main, int x, int y)
{
	t_map	*map;

	map = main->map;
	map->current.y = y;
	map->current.x = x;
	map->img_player->instances[0].x = map->current.x / 50;
	map->img_player->instances[0].y = map->current.y / 50;
}

void	ft_player_rotation(t_main *main)
{
	ray_set_player_pose(main);
	raycast(main);
}

void	ft_player_move_2(t_inpt input, t_map *map, float pdx, float pdy)
{
	if (input.down == 1)
	{
		pdy = -sin(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (cos(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(get_main(0), map->current.direc, -pdx, -pdy);
	}
	if (input.up == 1)
	{
		pdy = -sin(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (cos(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(get_main(0), map->current.direc, pdx, pdy);
	}
	if (input.right == 1)
	{
		pdy = cos(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (sin(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(get_main(0), map->current.direc, pdx, pdy);
	}
	if (input.left == 1)
	{
		pdy = cos(deg_to_rad(map->current.direc)) * input.speed;
		pdx = (sin(deg_to_rad(map->current.direc)) * input.speed);
		player_move_wall(get_main(0), map->current.direc, -pdx, -pdy);
	}
}

void	ft_player_move(t_main *main, t_inpt input)
{
	t_map	*map;
	float	pdx;
	float	pdy;

	pdx = 0.0;
	pdy = 0.0;
	map = main->map;
	ft_player_move_2(input, map, pdx, pdy);
}
