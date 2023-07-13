/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:26:05 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 15:26:26 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_coor	get_case_player(t_main *main)
{
	t_coor	case_coor;

	case_coor.x = main->map->current.x / MAP_RES;
	case_coor.y = main->map->current.y / MAP_RES;
	case_coor.x = case_coor.x * MAP_RES;
	case_coor.y = case_coor.y * MAP_RES;
	return (case_coor);
}

t_coor	get_case_coor(t_coor coor)
{
	t_coor	case_coor;

	case_coor.x = coor.x / MAP_RES;
	case_coor.y = coor.y / MAP_RES;
	case_coor.x = case_coor.x * MAP_RES;
	case_coor.y = case_coor.y * MAP_RES;
	return (case_coor);
}

t_coor	get_case_dbcoor(t_dblcoor coor)
{
	t_coor	case_coor;

	case_coor.x = coor.x / MAP_RES;
	case_coor.y = coor.y / MAP_RES;
	case_coor.x = case_coor.x * MAP_RES;
	case_coor.y = case_coor.y * MAP_RES;
	return (case_coor);
}

t_coor	get_center_player(t_main *main)
{
	t_coor	case_coor;

	case_coor.x = main->map->current.x + PLAYER_RES / 2;
	case_coor.y = main->map->current.y + PLAYER_RES / 2;
	return (case_coor);
}

t_dblcoor	get_dblcenter_player(t_main *main)
{
	t_dblcoor	case_coor;

	case_coor.x = main->map->current.x + PLAYER_RES / 2;
	case_coor.y = main->map->current.y + PLAYER_RES / 2;
	return (case_coor);
}
