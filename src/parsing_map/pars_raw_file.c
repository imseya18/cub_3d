/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:49 by mmorue            #+#    #+#             */
/*   Updated: 2023/07/06 13:45:37 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**check_routine(char *raw_map, char **texture, char *to_compare)
{
	char	tab[3];

	tab[0] = ' ';
	tab[1] = '\t';
	tab[2] = '\0';
	if (!texture)
	{
		texture = ft_split_modif(raw_map, tab);
		if (ft_strcmp(texture[0], to_compare) != 0
			|| strlen_doubletab(texture) != 2)
			ft_errormap("Wrong texture format");
	}
	else
		ft_errormap("Double texture");
	return (texture);
}

int	check_valide_format(char *raw_map, int *i, t_texture *text)
{
	if (raw_map[*i] == 'N')
		text->no = check_routine(raw_map, text->no, "NO");
	if (raw_map[*i] == 'S')
		text->so = check_routine(raw_map, text->so, "SO");
	if (raw_map[*i] == 'W')
		text->we = check_routine(raw_map, text->we, "WE");
	if (raw_map[*i] == 'E')
		text->ea = check_routine(raw_map, text->ea, "EA");
	if (raw_map[*i] == 'D')
		text->dr = check_routine(raw_map, text->dr, "DO");
	return (0);
}

char	**check_color_format(char *raw_map, int *i, char **rgb)
{
	int		k;
	char	*color_tab;
	char	tab[4];

	tab[0] = ' ';
	tab[1] = ',';
	tab[2] = '\t';
	tab[3] = '\0';
	k = *i;
	if (raw_map[k + 1] != ' ' && raw_map[k + 1] != '\t')
		ft_errormap("Wrong color format");
	k++;
	while (raw_map[k] == ' ' || raw_map[k] == '\t')
		k++;
	color_tab = &raw_map[k];
	check_color_char(color_tab);
	if (rgb)
		ft_errormap("wrong double color");
	rgb = ft_split_modif(color_tab, tab);
	if (strlen_doubletab(rgb) != 3)
		ft_errormap("Wrong color format");
	return (rgb);
}

int	check_char(char *raw_map, int *i, t_main *main)
{
	if (raw_map[*i] == '\0')
		return (0);
	else if (raw_map[*i] != 'N' && raw_map[*i] != 'S' && raw_map[*i] != 'W'
		&& raw_map[*i] != 'E' && raw_map[*i] != 'F' && raw_map[*i] != 'C'
		&& raw_map[*i] != '1' && raw_map[*i] != ' ' && raw_map[*i] != '\n'
		&& raw_map[*i] != '\t' && raw_map[*i] != 'D')
		ft_errormap("Wrong format of file");
	else if (raw_map[*i] == 'N' || raw_map[*i] == 'S' || raw_map[*i] == 'W'
		|| raw_map[*i] == 'E' || raw_map[*i] == 'D')
		check_valide_format(raw_map, i, main->text);
	else if (raw_map[*i] == 'F')
	{
		main->text->f = check_color_format(raw_map, i, main->text->f);
		convert_color(main->text->f, main->sol);
	}
	else if (raw_map[*i] == 'C')
	{
		main->text->c = check_color_format(raw_map, i, main->text->c);
		convert_color(main->text->c, main->ciel);
	}
	return (0);
}

void	ft_pars_raw_map(char **raw_map, t_main *main)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (raw_map[k] != 0)
	{
		while (raw_map[k][i] != 0 && raw_map[k][i] != '1'
			&& raw_map[k][i] != '0')
		{
			skip_space(raw_map[k], &i);
			if (check_char(raw_map[k], &i, main) == 0)
				break ;
			i++;
		}
		if (raw_map[k][i] == '1' || raw_map[k][i] == '0')
			break ;
		i = 0;
		k++;
	}
	if (check_valide_texture(main->text) == 0 || raw_map[k] == 0)
		ft_errormap("Wrong file format");
	ft_copy_map(raw_map, main, k);
	ft_door_texture(main);
}
