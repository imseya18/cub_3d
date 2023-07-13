/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_clean_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:03:06 by mmorue            #+#    #+#             */
/*   Updated: 2023/07/06 13:45:21 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_door(char **map, int i, int k, int *door)
{
	*door = 1;
	if ((map[k - 1][i] == '1' && map[k + 1][i] == '1')
			|| (map[k][i - 1] == '1' && map[k][i + 1] == '1'))
		return ;
	else
		ft_errormap("No wall for door");
}

void	ft_door_texture(t_main *main)
{
	if (main->door == 1 && !main->text->dr)
		ft_errormap("Door in map but no texture found");
	if (main->door == 0 && main->text->dr)
		ft_errormap("No door in map but texture found");
}
