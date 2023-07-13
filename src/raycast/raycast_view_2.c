/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:56:48 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 14:39:44 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int32_t	get_pix(int pose, int i, int pixel_col, int height)
{
	t_main	*main;
	int		x;
	int		y;

	main = get_main(0);
	x = pixels_convert_ratio_width(main, main->png[pose], pixel_col);
	y = pixels_convert_ratio_height(main, main->png[pose], i, height);
	return (main->png[pose].pixels[x][y]);
}

void	pixels_display(t_hit box, int i, int height, int x)
{
	int		y;
	t_map	*mp;

	mp = get_main(0)->map;
	y = HEIGHT / 2 - height / 2;
	if (box.hit_type == 2)
		mlx_put_pixel(mp->view, x, i + y, get_pix(4, i, box.pixel_col, height));
	else if (box.orientation == 1)
		mlx_put_pixel(mp->view, x, i + y, get_pix(0, i, box.pixel_col, height));
	else if (box.orientation == 2)
		mlx_put_pixel(mp->view, x, i + y, get_pix(1, i, box.pixel_col, height));
	else if (box.orientation == 3)
		mlx_put_pixel(mp->view, x, i + y, get_pix(2, i, box.pixel_col, height));
	else if (box.orientation == 4)
		mlx_put_pixel(mp->view, x, i + y, get_pix(3, i, box.pixel_col, height));
}
