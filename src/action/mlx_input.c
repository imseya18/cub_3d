/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:50:28 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:21:30 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_player_init_input(t_inpt *input, t_main *main)
{
	input->right = 0;
	input->left = 0;
	input->up = 0;
	input->down = 0;
	input->speed = PLY_SPEED * ft_delta_time(main);
}

int	player_get_move(t_main *main)
{
	t_inpt	input;

	ft_player_init_input(&input, main);
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_D))
		input.right = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_A))
		input.left = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_W))
		input.up = 1;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_S))
		input.down = 1;
	if (input.up + input.down + input.left + input.right > 1)
		input.speed = input.speed - (input.speed / 3.5);
	if (input.up + input.down + input.left + input.right > 0)
	{
		ft_player_move(main, input);
		return (1);
	}
	return (0);
}

int	player_get_rotation(t_main *main)
{
	t_map	*map;

	map = main->map;
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_LEFT))
	{
		map->current.direc += 4;
		if (map->current.direc >= 360)
			map->current.direc = 0;
		return (1);
	}
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_RIGHT))
	{
		map->current.direc -= 4;
		if (map->current.direc < 0)
			map->current.direc = 359;
		return (1);
	}
	return (mlx_mouse(main));
}

int	mlx_mouse_2(t_main *main, int mx, t_map	*map)
{
	if (mx < WIDTH / 2 - 5)
	{
		map->current.direc += 4;
		if (map->current.direc >= 360)
			map->current.direc = 0;
		mlx_set_mouse_pos(main->mlx, WIDTH / 2, HEIGHT / 2);
		return (1);
	}
	else if (mx > WIDTH / 2 + 5)
	{
		map->current.direc -= 4;
		if (map->current.direc < 0)
			map->current.direc = 359;
		mlx_set_mouse_pos(main->mlx, WIDTH / 2, HEIGHT / 2);
		return (1);
	}
	return (0);
}

int	mlx_mouse(t_main *main)
{
	int		mx;
	int		my;
	t_map	*map;

	map = main->map;
	mlx_get_mouse_pos(main->mlx, &mx, &my);
	if (main->pause == 0 && (mx > 0 && mx < WIDTH) && (my > 0 && my < HEIGHT))
		return (mlx_mouse_2(main, mx, map));
	return (0);
}
