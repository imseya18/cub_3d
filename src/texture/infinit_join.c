/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinit_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:52:38 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 15:30:33 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	infinit_join_fill(char *full_join, char *argu, int *i)
{
	int	a;

	a = 0;
	while (argu[a])
		full_join[(*i)++] = argu[a++];
}

char	*infinit_join(const char *fmt, ...)
{
	va_list	arg;
	char	*full_join;
	int		argums;
	int		size;
	int		i;

	size = 0;
	if (!fmt)
		return (0);
	argums = ft_atoi(fmt);
	va_start (arg, fmt);
	i = -1;
	while (++i < argums)
		size += ft_strlen_(va_arg(arg, char *));
	va_end (arg);
	full_join = ftm_malloc((size + 1) * sizeof(char));
	full_join[size] = 0;
	va_start (arg, fmt);
	i = -1;
	size = 0;
	while (++i < argums)
		infinit_join_fill(full_join, va_arg(arg, char *), &size);
	va_end (arg);
	return (full_join);
}
