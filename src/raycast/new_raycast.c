/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:15:25 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 17:18:57 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dblcoor	line_raycast_new_dda_incr(t_main *main, float rad, int step,
	t_dblcoor val)
{
	t_dblcoor	dcoor;
	t_dda		dda;

	dcoor.x = main->ray->x;
	dcoor.y = main->ray->y;
	dda.xdda = val.x / (float)step;
	dda.ydda = val.y / (float)step;
	dda.y_case = get_case_coor(get_center_player(main)).y;
	if (!(rad < PI))
		dda.y_case += MAP_RES;
	dda.x_case = get_case_coor(get_center_player(main)).x;
	if (!((rad > PI / 2) && (rad < (PI / 2) * 3)))
		dda.x_case += MAP_RES;
	dda.i = 0;
	while (dda.i < step && dcoor.y >= 0)
	{
		if (daa_stairs(&dda, &dcoor, rad, main) == 1)
			return (dcoor);
		dcoor.x += dda.xdda;
		dcoor.y += dda.ydda;
		dda.i++;
	}
	return (dcoor);
}

t_dblcoor	line_raycast_new_dda(t_main *main, float rad, t_dblcoor	max)
{
	int			dx;
	int			dy;
	int			step;
	t_dblcoor	dcoor;

	dx = max.x - main->ray->x;
	dy = max.y - main->ray->y;
	step = get_max(get_abs(dx), get_abs(dy));
	dcoor.x = dx;
	dcoor.y = dy;
	return (line_raycast_new_dda_incr(main, rad, step, dcoor));
}

t_dblcoor	line_raycast_new(t_main *main, float rad)
{
	t_dblcoor	val;
	t_dblcoor	a;
	t_dblcoor	b;
	int			max;

	a.x = 0;
	a.y = 0;
	b.x = main->map->width * MAP_RES;
	b.y = main->map->height * MAP_RES;
	max = distance_diff(a, b);
	val.x = main->ray->x + cos(rad) * max;
	val.y = main->ray->y - sin(rad) * max;
	return (line_raycast_new_dda(main, rad, val));
}

void	raycast_flastlight_new(t_main *main, float angle)
{
	int			i;
	t_dblcoor	val;
	float		step;
	float		temp;

	step = 0.046875;
	i = 0;
	angle += step * 640;
	while (i < 1280)
	{
		temp = angle;
		if (angle < 0)
			temp += 359;
		else if (angle >= 360)
			temp = angle - 360;
		val = line_raycast_new(main, deg_to_rad(temp));
		add_ray_filtre(main, val, i, temp);
		angle -= step;
		i++;
	}
	apply_filtre(main);
	read_ray(main);
}
