/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:45:56 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 14:08:49 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	height_distance(int distance, float angle)
{
	int			height;
	t_map		*map;

	map = get_main(0)->map;
	distance = distance * cos(deg_to_rad(map->current.direc - angle));
	height = HEIGHT * 500 / distance * 1;
	if (height < 0)
		height = 0;
	return (height);
}

int	get_diff(int a, int b)
{
	int	out;

	out = a - b;
	return (get_abs(out));
}
