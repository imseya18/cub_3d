/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:52:40 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/28 17:56:53 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	strlen_doubletab(char **tab)
{
	int	k;

	k = 0;
	while (tab[k])
		k++;
	return (k);
}

void	skip_space(char *raw_map, int *i)
{
	while (raw_map[*i] == ' ' || raw_map[*i] == '\n' || raw_map[*i] == '\t')
		*i = *i + 1;
}

void	check_color_char(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != ','
			&& str[i] != '\t')
			ft_errormap("Wrong char in color");
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
		ft_errormap("wrong color format");
}

int	check_valide_texture(t_texture *text)
{
	if (!text->no || !text->we || !text->so || !text->ea || !text->f
		|| !text->c)
		return (0);
	else
		return (1);
}

int	check_char_for_map(char	*tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		if (tab[i] == '1' || tab[i] == '0' || tab[i] == 'N' || tab[i] == 'S'
			|| tab[i] == 'E' || tab[i] == 'W' || tab[i] == 'D')
			return (1);
	return (0);
}
