/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:01:12 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 13:01:16 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_init_build(t_main *main)
{
	main->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	return (1);
}
