/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 14:39:32 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_main *main, int x, int height, t_hit box)
{
	int		y;
	int		i;
	int		x_max;

	y = HEIGHT / 2 - height / 2;
	x = x * 2;
	x_max = x + 2;
	while (x < x_max)
	{
		i = -1;
		while (++i < height)
		{
			if (y + i >= 0 && y + i < HEIGHT)
				pixels_display(box, i, height, x);
		}
		x++;
	}
	(void)main;
}

int	pixels_convert_ratio_width(t_main *main, t_pixtex png, int i)
{
	int	out;

	out = (i - 0) * (png.width - 1 - 0) / (MAP_RES - 0) + 0;
	(void)main;
	return (out);
}

int	pixels_convert_ratio_height(t_main *main, t_pixtex png, int i, int height)
{
	int	out;

	out = (i - 0) * (png.height - 1 - 0) / (height - 0) + 0;
	(void)main;
	return (out);
}
