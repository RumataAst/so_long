/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:43:59 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:31:19 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_check_first_row(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_last_row(char *map)
{
	size_t	i;
	int		last_row_found;

	i = 0;
	last_row_found = 0;
	while (map[i] != '\0')
		i++;
	while (i >= 0 && map[i] != '\n')
		i--;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			last_row_found = 1;
		else if (map[i] != '1')
			return (1);
		i++;
	}
	if (last_row_found)
		return (0);
	else
		return (1);
}

static int	ft_check_near_newlines(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (i > 0 && map[i - 1] != '1')
				return (1);
			if (map[i + 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_walls(char *map)
{
	if (ft_check_first_row(map) != 0
		|| ft_check_last_row(map) != 0
		|| ft_check_near_newlines(map) != 0)
		return (1);
	return (0);
}
