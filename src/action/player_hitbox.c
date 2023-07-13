/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hitbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:36:39 by loculy            #+#    #+#             */
/*   Updated: 2023/06/27 15:53:56 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_wall_collision(int x, int y, t_player current, t_coor wall)
{
	t_player	move;

	move = current;
	move.x += x;
	move.y += y;
	if ((!(move.x + PLAYER_RES < wall.x) && !(move.x > wall.x + MAP_RES))
		&& (!(move.y + PLAYER_RES < wall.y)
			&& !(move.y > wall.y + MAP_RES)))
		return (1);
	return (0);
}

void	player_move_wall(t_main *main, int type, int x, int y)
{
	int		i;
	t_map	*map;

	i = 0;
	map = main->map;
	while (i < map->wall_size)
	{
		if (is_wall_collision(x, y, map->current, map->wall[i]))
			return ;
		i++;
	}
	player_move_door(main, type, x, y);
}

void	player_move_door(t_main *mn, int type, int x, int y)
{
	int		i;
	t_map	*mp;

	i = 0;
	mp = mn->map;
	while (i < mp->door_size)
	{
		if (mp->door[i].open == 0
			&& is_wall_collision(x, y, mp->current, mp->door[i].coor))
			return ;
		i++;
	}
	(void)type;
	update_player(mn, x, y);
}
