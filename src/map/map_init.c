/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:03:31 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 16:13:33 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coor	map_add_hitbox(int x, int y)
{
	t_coor	coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}

t_map	init_map_wall(t_map map)
{
	int		i;
	int		y;
	int		x;

	map.wall_size = get_map_hitbox_size(map.map, '1');
	if (map.wall_size == 0)
		return (map);
	map.wall = ftm_malloc((map.wall_size) * sizeof(t_coor));
	i = 0;
	y = 0;
	while (map.map[y] && map.map[y] != 0)
	{
		x = 0;
		while (map.map[y] != 0 && map.map[y][x] != 0 && map.map[y][x] != '\n')
		{
			if (map.map[y][x] == '1')
				map.wall[i++] = map_add_hitbox(x * MAP_RES, y * MAP_RES);
			x++;
		}
		y++;
	}
	return (map);
}

t_map	init_map_door(t_map map)
{
	int		i;
	int		y;
	int		x;

	map.door_size = get_map_hitbox_size(map.map, 'D');
	if (map.door_size == 0)
		return (map);
	map.door = ftm_malloc((map.door_size) * sizeof(t_door));
	i = 0;
	y = 0;
	while (map.map[y] && map.map[y] != 0)
	{
		x = 0;
		while (map.map[y] != 0 && map.map[y][x] != 0 && map.map[y][x] != '\n')
		{
			if (map.map[y][x] == 'D')
			{
				map.door[i].coor = map_add_hitbox(x * MAP_RES, y * MAP_RES);
				map.door[i++].open = 0;
			}
			x++;
		}
		y++;
	}
	return (map);
}

t_map	init_map(t_map map)
{
	t_coor	size;

	size = get_map_maxsize(map.map);
	map = init_map_wall(map);
	map = init_map_door(map);
	map = init_map_player(map);
	map.width = size.x;
	map.height = size.y;
	return (map);
}

void	init_main(t_main *main)
{
	mouse_mode_t	mode;

	main->raycast_arr = ftm_malloc((1280) * sizeof(t_hit));
	main->pause = 0;
	main->fire = 0;
	main->fire_anim = 0;
	main->load = 0;
	main->load_anim = 0;
	main->ammo = 20;
	mode = MLX_MOUSE_HIDDEN;
	mlx_set_cursor_mode(main->mlx, mode);
	display_ground_sky(main);
	main->map->view = ftm_malloc((1) * sizeof(mlx_image_t));
	main->map->view = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	if (!main->map->view
		|| (mlx_image_to_window(main->mlx, main->map->view, 0, 0) < 0))
		ft_errormap("No space left");
	main->map->hand = ftm_malloc((29) * sizeof(mlx_image_t));
}
