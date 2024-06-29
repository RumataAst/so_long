/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:05:31 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 15:04:00 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	get_first_line_width(char *map)
{
	int	width;

	width = 0;
	while (*map != '\n' && *map != '\0')
	{
		width++;
		map++;
	}
	return (width);
}

static int	check_all_lines_width(char *map, int width)
{
	int	width_next;

	width_next = 0;
	while (*map)
	{
		if (*map != '\n')
			width_next++;
		else
		{
			if (width != width_next)
				return (1);
			width_next = 0;
		}
		map++;
	}
	if (width != width_next && width_next != 0)
		return (1);
	return (0);
}

int	ft_check_rec(char *map)
{
	int	width;
	int	height;

	height = 1;
	width = get_first_line_width(map);
	if (check_all_lines_width(map, width) == 1)
		return (1);
	while (*map != '\n' && *map != '\0')
		map++;
	while (*map)
	{
		if (*map == '\n')
			height++;
		map++;
	}
	if (height < 3)
		return (1);
	return (0);
}
