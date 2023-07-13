/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:46:27 by loculy            #+#    #+#             */
/*   Updated: 2023/07/11 14:45:59 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_hook(void *param)
{
	t_main	*main;
	int		update;

	update = 0;
	main = param;
	update += player_get_move(main);
	update += player_get_rotation(main);
	update += player_get_action(main);
	get_fire(main);
	get_reload(main, 0);
	if (update > 0)
		ft_player_rotation(main);
}

void	init_main_rgb(t_main *main, char *argv)
{
	main->text = ftm_malloc(sizeof(t_texture));
	main->ciel = ftm_malloc(sizeof(t_rgb));
	main->sol = ftm_malloc(sizeof(t_rgb));
	ft_bzero(main->text, sizeof(t_texture));
	get_file(main, argv);
	ft_pars_raw_map(main->clean_file, main);
}

void	init_main_mlx(t_main *main, t_raycast *raycast)
{
	get_main(main);
	ft_mlx_init_build(main);
	init_main(main);
	display_mini_map(main);
	display_mini_map_player(main);
	init_ray_view(main);
	main->cooldown = init_cooldown();
	main->ray = raycast;
	ray_set_player_pose(main);
	load_texture(main);
	hand_display(main, 0);
	wall_textures_load(main);
	load_pixels(main);
}

void	mlx_destroyer_all(t_main *main)
{
	int	i;

	i = -1;
	while (++i < 29)
	{
		mlx_delete_texture(main->map->hand_texture[i]);
		mlx_delete_image(main->mlx, main->map->hand[i]);
	}
	mlx_delete_image(main->mlx, main->map->ground_sky[0]);
	mlx_delete_image(main->mlx, main->map->ground_sky[1]);
	mlx_delete_image(main->mlx, main->map->img_player);
	mlx_delete_image(main->mlx, main->map->ray_lines);
	mlx_delete_image(main->mlx, main->map->view);
	i = -1;
	while (++i < main->map->bck_size)
		mlx_delete_image(main->mlx, main->map->img_bck[i]);
}

int	main(int argc, char **argv)
{
	t_main		main;
	t_map		map;
	t_raycast	raycast;

	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	init_main_rgb(&main, argv[1]);
	map.map = main.map_tab;
	map = init_map(map);
	main.map = &map;
	init_main_mlx(&main, &raycast);
	ft_player_rotation(&main);
	mlx_loop_hook(main.mlx, ft_hook, &main);
	mlx_loop(main.mlx);
	mlx_destroyer_all(&main);
	mlx_terminate(main.mlx);
	ftm_free_all();
	return (0);
}
