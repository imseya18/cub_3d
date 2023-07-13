/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_files_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:59:24 by mmorue            #+#    #+#             */
/*   Updated: 2023/07/05 16:42:28 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convert_color(char **color, t_rgb *rgb)
{
	rgb->r = ft_atoi(color[0]);
	rgb->g = ft_atoi(color[1]);
	rgb->b = ft_atoi(color[2]);
	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255)
		ft_errormap("wrong RGB format");
}

char	*ft_strdup_(char *s1)
{
	char	*m;
	int		i;
	int		sizes1;

	i = 0;
	sizes1 = ft_strlen_(s1);
	m = ftm_malloc((sizes1 + 1) * sizeof(char));
	if (!m)
		return (0);
	while (i < sizes1)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

void	ft_copy_map(char **raw_map, t_main *main, int k)
{
	int	start_map;
	int	i;

	start_map = k;
	while (raw_map[k] && check_char_for_map(raw_map[k]) == 1)
		k++;
	if (raw_map[k] != 0)
		ft_errormap("Wrong file format");
	if (k - start_map > 30)
		ft_errormap("map too long");
	main->map_tab = ftm_malloc((k - start_map + 1) * sizeof(char *));
	main->map_tab[k - start_map] = 0;
	i = 0;
	while (start_map < k)
	{
		main->map_tab[i] = ft_strdup_(raw_map[start_map]);
		start_map++;
		i++;
	}
	ft_free_tab(raw_map);
	ft_pars_clean_map(main->map_tab, main);
}
