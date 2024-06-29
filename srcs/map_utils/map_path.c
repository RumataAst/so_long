/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:03:44 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 15:22:33 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	path_e_s(t_map_path *map_path, int row, int col, char l)
{
	map_path->map[row][col] = l;
	if (l == 'P')
	{
		map_path->pl_x = row;
		map_path->pl_y = col;
	}
	else if (l == 'E')
	{
		map_path->exit_x = row;
		map_path->exit_y = col;
	}
}

void	ft_map_path(char *map_string, t_map_path *map_path)
{
	int		row;
	int		col;
	size_t	i;

	row = 0;
	col = 0;
	i = 0;
	while (map_string[i])
	{
		if (map_string[i] == '\n')
		{
			row++;
			col = 0;
		}
		else
		{
			path_e_s(map_path, row, col, map_string[i]);
			col++;
		}
		i++;
	}
	map_path->rows = row + 1;
	map_path->cols = col;
}

int	ft_flood_fill(t_map_path *map_path, int x, int y)
{
	if (x < 0 || x >= map_path->rows || y < 0 || y >= map_path->cols
		|| map_path->map[x][y] == '1' || map_path->map[x][y] == 'V')
		return (0);
	if (x == map_path->exit_x && y == map_path->exit_y)
		return (1);
	map_path->map[x][y] = 'V';
	if (ft_flood_fill(map_path, x - 1, y)
		|| ft_flood_fill(map_path, x + 1, y)
		|| ft_flood_fill(map_path, x, y - 1)
		|| ft_flood_fill(map_path, x, y + 1))
		return (1);
	return (0);
}
