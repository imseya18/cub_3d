/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycast_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:53:19 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:05:51 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	daa_stairs(t_dda *dda, t_dblcoor *dcoor, float rad, t_main *main)
{
	if (round(dcoor->y) == dda->y_case)
	{
		dcoor->y = round(dcoor->y);
		if (raycast_get_collision(*dcoor, main) == 1)
			return (1);
		else if (rad < PI)
			dda->y_case -= MAP_RES;
		else
			dda->y_case += MAP_RES;
	}
	if (round(dcoor->x) == dda->x_case)
	{
		dcoor->x = round(dcoor->x);
		if (raycast_get_collision(*dcoor, main) == 1)
			return (1);
		else if ((rad > PI / 2) && (rad < (PI / 2) * 3))
			dda->x_case -= MAP_RES;
		else
			dda->x_case += MAP_RES;
	}
	return (0);
}
