/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:28:04 by mmorue            #+#    #+#             */
/*   Updated: 2023/07/04 14:42:52 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	checkline(char *buffer)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			size++;
		i++;
	}
	return (size);
}

int	read_map(int fd)
{
	char	buffer[2];
	int		size;

	buffer[1] = '\0';
	size = 1;
	if (read(fd, 0, 0) < 0 || fd < 0)
	{
		close(fd);
		return (ft_errormap("invalid file"));
	}
	while (read(fd, buffer, 1) > 0)
		size += checkline(buffer);
	close(fd);
	return (size);
}

int	ft_errormap(char *str)
{
	int	k;

	k = ft_strlen(str);
	write(1, "Error\n", 6);
	write(1, str, k);
	write(1, "\n", 1);
	ftm_free_all();
	exit (1);
}

int	check_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
		return (ft_errormap("map isn't .cub"));
	return (1);
}

int	get_file(t_main *main, char *str)
{
	int		i;
	int		size;
	int		fd;
	char	**raw_map;

	i = 0;
	size = read_map(ftm_open(str, O_RDONLY));
	if (size < 9)
		return (ft_errormap("invalide number of line, can't be a valid map"));
	raw_map = ftm_malloc((size + 1) * sizeof(char *));
	raw_map[size] = 0;
	main->clean_file = ftm_malloc((size + 1) * sizeof(char *));
	main->clean_file[size] = 0;
	fd = ftm_open(str, O_RDONLY);
	while (i < size)
		raw_map[i++] = get_next_line(fd);
	clean_map(main, raw_map);
	ft_free_tab(raw_map);
	ftm_close(fd);
	return (0);
}
