/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:02:21 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 14:47:31 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray_view(t_main *main)
{
	t_map	*map;

	map = main->map;
	map->ray_lines = ftm_malloc((1) * sizeof(mlx_image_t));
	map->ray_lines = mlx_new_image(main->mlx, get_map_maxsize(map->map).x
			* MN_MAP_RES, get_map_maxsize(map->map).y * MN_MAP_RES);
	if (!map->ray_lines || (mlx_image_to_window(main->mlx, map->ray_lines, 0, 0)
			< 0))
		exit(0);
	fill_color_image(map->ray_lines, ft_pixel(255, 255, 255, 0));
}

int	get_abs(int value)
{
	if (value == -2147483648)
		return (2147483647);
	else if (value < 0)
		return (-value);
	else
		return (value);
}

void	dda_incr(float x, float y, int step, t_coor dcoor)
{
	float	xdda;
	float	ydda;
	int		i;
	t_main	*main;
	t_map	*map;

	main = get_main(0);
	map = main->map;
	xdda = dcoor.x / (float)step;
	ydda = dcoor.y / (float)step;
	i = 0;
	while (i < step && i < 5000)
	{
		if (x >= 0 && x < map->width * MAP_RES && y >= 0
			&& y < map->height * MAP_RES)
			mlx_put_pixel(map->ray_lines, (uint32_t)x, (uint32_t)y,
				ft_pixel(255, 225, 70, 255));
		x += xdda;
		y += ydda;
		i++;
	}
}

void	draw_line(int xa, int ya, int xb, int yb)
{
	int		dx;
	int		dy;
	int		step;
	t_coor	dcoor;

	dx = xb - xa;
	dy = yb - ya;
	step = get_max(get_abs(dx), get_abs(dy));
	dcoor.x = dx;
	dcoor.y = dy;
	dda_incr((float)xa, (float)ya, step, dcoor);
}
