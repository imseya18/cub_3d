/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_filtre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:04:21 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:14:17 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_ray_filtre(t_main *main, t_dblcoor val, int i, float angle)
{
	main->raycast_arr[i] = get_hit_texture_box(main, val);
	main->raycast_arr[i].coor = val;
	main->raycast_arr[i].distance = height_distance(distance_from_main(main,
				val), angle);
}

void	apply_filtre(t_main *main)
{
	int			i;
	t_hit		*box;

	i = -1;
	box = main->raycast_arr;
	while (++i < 1280)
	{
		if (i > 2 && i < 1278 && ((int)round(box[i].coor.x) % 500 == 0
				&& (int)round(box[i].coor.y) % 500 == 0))
		{
			if (get_diff(box[i - 1].distance, box[i].distance)
				< get_diff(box[i + 1].distance, box[i].distance))
			{
				box[i].orientation = box[i - 2].orientation;
				box[i].hit_type = box[i - 2].hit_type;
				box[i].pixel_col = box[i - 2].pixel_col;
			}
			else
			{
				box[i].orientation = box[i + 2].orientation;
				box[i].hit_type = box[i + 2].hit_type;
				box[i].pixel_col = box[i + 2].pixel_col;
			}
		}
	}
}

void	read_ray(t_main *main)
{
	int			i;
	t_hit		*box;

	i = 0;
	box = main->raycast_arr;
	while (i < 1280)
	{
		draw_rectangle(main, i, box[i].distance, box[i]);
		i++;
	}
}
