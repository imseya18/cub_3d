/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:48:24 by loculy            #+#    #+#             */
/*   Updated: 2023/06/29 21:33:14 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	interact_door(t_main *main, t_door *door, int cldwn)
{
	if (is_wall_collision(0, 0, main->map->current, door->coor))
		return (cldwn);
	if (door->open == 0)
		door->open = 1;
	else
		door->open = 0;
	return (1);
}

void	check_doors(t_main *main, t_map	*map)
{
	t_coor	case_coor;
	int		cldwn;
	int		i;

	i = -1;
	cldwn = 0;
	case_coor = get_case_player(main);
	while (++i < map->door_size)
	{
		if (case_coor.x - MAP_RES == map->door[i].coor.x
			&& case_coor.y == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x + MAP_RES == map->door[i].coor.x
			&& case_coor.y == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x == map->door[i].coor.x
			&& case_coor.y - MAP_RES == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
		else if (case_coor.x == map->door[i].coor.x
			&& case_coor.y + MAP_RES == map->door[i].coor.y)
			cldwn = interact_door(main, &(map->door[i]), cldwn);
	}
	if (cldwn == 1)
		main->cooldown->door = get_time(main) + 150;
}

void	pause_game(t_main *main)
{
	mouse_mode_t	mode;

	if (main->pause == 0)
	{
		mode = MLX_MOUSE_NORMAL;
		main->pause = 1;
	}
	else
	{
		main->pause = 0;
		mode = MLX_MOUSE_HIDDEN;
	}
	mlx_set_cursor_mode(main->mlx, mode);
	main->cooldown->pause = get_time(main) + 150;
}

int	player_get_action(t_main *main)
{
	t_map	*map;

	map = main->map;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_E))
	{
		if (get_time(main) >= main->cooldown->door)
		{
			check_doors(main, map);
			return (1);
		}
	}
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_SPACE))
		if (get_time(main) >= main->cooldown->pause)
			pause_game(main);
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_ESCAPE))
	{
		ftm_free_all();
		exit(0);
	}
	return (0);
}
