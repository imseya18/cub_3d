/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:10:04 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 17:23:29 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_ammo(t_main *main, int ammo)
{
	char	*res;

	main->ammo = ammo;
	write(1, "ammo: ", 6);
	res = ft_itoa_(main->ammo);
	write(1, res, ft_strlen_(res));
	ftm_free(res);
	write(1, "/20\n", 4);
}

void	hand_display(t_main *main, int pose)
{
	int	i;

	i = 0;
	while (i < 29)
		main->map->hand[i++]->enabled = false;
	main->map->hand[pose]->enabled = true;
}

void	load_texture(t_main *main)
{
	int	i;

	i = 0;
	main->map->hand_texture = ftm_malloc((29) * sizeof(mlx_texture_t));
	while (i < 29)
	{
		main->map->hand_texture[i] = mlx_load_png(infinit_join("3",
					"textures/gun/PPSH_", ft_itoa_(i), ".png"));
		if (!main->map->hand_texture[i])
			ft_errormap("No space left");
		main->map->hand[i] = mlx_texture_to_image(main->mlx,
				main->map->hand_texture[i]);
		if (!main->map->hand[i] || (mlx_image_to_window(main->mlx,
					main->map->hand[i], 1000, 900) < 0))
			ft_errormap("No space left");
		main->map->hand[i]->enabled = false;
		i++;
	}
}

void	get_fire(t_main *main)
{
	if (mlx_is_mouse_down(main->mlx, MLX_MOUSE_BUTTON_LEFT) == true
		|| mlx_is_key_down((void *)main->mlx, MLX_KEY_F))
	{
		if (main->fire == 0 && main->load == 0)
		{
			if (main->ammo <= 0)
				return (get_reload(main, 1));
			main->fire = 1;
			change_ammo(main, main->ammo - 1);
			main->fire_anim = get_time(main) + 40;
		}
	}
	if (main->fire > 0 && get_time(main) >= main->fire_anim)
	{
		main->fire += 1;
		if (main->fire > 3)
		{
			hand_display(main, 0);
			main->fire = 0;
		}
		else
			hand_display(main, main->fire - 1);
		main->fire_anim = get_time(main) + 40;
	}
}

void	get_reload(t_main *main, int force)
{
	if (mlx_is_key_down((void *)main->mlx, MLX_KEY_R) || force == 1)
	{
		if (main->load == 0 && main->fire == 0)
		{
			main->load = 3;
			write(1, "Reloading...\n", 13);
			main->load_anim = get_time(main) + 50;
		}
	}
	if (main->load > 0 && get_time(main) >= main->load_anim)
	{
		main->load += 1;
		if (main->load > 26)
		{
			hand_display(main, 0);
			change_ammo(main, 20);
			main->load = 0;
		}
		else
			hand_display(main, main->load - 1);
		main->load_anim = get_time(main) + 50;
	}
}
