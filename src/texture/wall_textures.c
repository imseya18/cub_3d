/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:22:49 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:21:55 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_texture_secu(int i, char *str, t_texture *tex)
{
	tex->all[i] = mlx_load_png(str);
	if (!tex->all[i])
		ft_errormap("Invalid texture file");
}

void	wall_textures_load(t_main *main)
{
	t_texture	*tex;
	int			size;
	int			i;

	tex = main->text;
	i = 0;
	if (main->door == 1)
		size = 5;
	else
		size = 4;
	tex->all = ftm_malloc((size) * sizeof(mlx_texture_t));
	main->png = ftm_malloc((size) * sizeof(t_pixtex));
	load_texture_secu(i++, tex->so[1], tex);
	load_texture_secu(i++, tex->no[1], tex);
	load_texture_secu(i++, tex->we[1], tex);
	load_texture_secu(i++, tex->ea[1], tex);
	if (main->door == 1)
		load_texture_secu(i++, tex->dr[1], tex);
}

t_pixtex	text_pixels_init(mlx_texture_t *tex)
{
	unsigned int	i;
	t_pixtex		out;

	i = 0;
	out.pixels = ftm_malloc((tex->width) * sizeof(int32_t *));
	out.height = tex->height;
	out.width = tex->width;
	while (i < tex->width)
		out.pixels[i++] = ftm_malloc((tex->height) * sizeof(int32_t));
	return (out);
}

t_pixtex	texture_to_pixels(mlx_texture_t *tex)
{
	t_pixtex		out;
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;

	y = 0;
	x = 0;
	i = 0;
	out = text_pixels_init(tex);
	while (i < tex->height * tex->width * tex->bytes_per_pixel)
	{
		if (x == tex->width)
		{
			x = 0;
			y++;
		}
		out.pixels[x][y] = ft_pixel(tex->pixels[i], tex->pixels[i + 1],
				tex->pixels[i + 2], tex->pixels[i + 3]);
		i += tex->bytes_per_pixel;
		x++;
	}
	return (out);
}

void	load_pixels(t_main *main)
{
	t_texture	*tex;
	int			i;

	i = 0;
	tex = main->text;
	while (i < 4 + main->door)
	{
		main->png[i] = texture_to_pixels(tex->all[i]);
		mlx_delete_texture(tex->all[i]);
		i++;
	}
}
