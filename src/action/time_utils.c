/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:10:33 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 16:16:22 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_delta_time(t_main *main)
{
	int		b;
	mlx_t	*mlx;

	mlx = main->mlx;
	b = (int)(mlx->delta_time * 100);
	if (b > 1)
		b = b / 2;
	return (b);
}

int	get_time(t_main *main)
{
	unsigned int	time;

	(void)main;
	time = mlx_get_time() * 1000;
	if (time >= 2147483646)
		time -= 2147483646;
	return ((int)time);
}

t_cooldown	*init_cooldown(void)
{
	t_cooldown	*cooldown;

	cooldown = ftm_malloc(sizeof(t_cooldown));
	cooldown->door = 0;
	cooldown->fire = 0;
	cooldown->pause = 0;
	return (cooldown);
}
