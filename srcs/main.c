/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:54 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:15:53 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	allocate_structs(t_map_path **map_path_d, t_end **map_end, t_game **game)
{
	*map_end = (t_end *)malloc(sizeof(t_end));
	if (*map_end == NULL)
	{
		perror("Failed to allocate memory for map_end");
		exit (-1);
	}
	*map_path_d = (t_map_path *)malloc(sizeof(t_map_path));
	if (*map_path_d == NULL)
	{
		perror("Failed to allocate memory for map_path_d");
		free(*map_end);
		exit (-1);
	}
	*game = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
	{
		perror("Failed to allocate memory for game");
		free(*map_end);
		free(*map_path_d);
		exit (-1);
	}
	return (0);
}

void	f_norminette_1(char *m_str, t_map_path *map_path_d, t_end *map_end)
{
	ft_map_path_init(map_path_d);
	ft_map_path(m_str, map_path_d);
	ft_end_init(map_end, m_str);
}

void	f_norminette_2(char *m_str, t_map_path *m_d, t_end *m_e, t_game *game)
{
	f_norminette_1(m_str, m_d, m_e);
	if (ft_flood_fill(m_d, m_d->pl_x, m_d->pl_y))
		ft_run_game(m_str, game, m_d, m_e);
	else
	{
		ft_printf("No path exists from player to exit.\n");
		free(m_str);
		ft_clean_struct(m_d, m_e, game);
	}
	if (m_str)
		free(m_str);
}

int	main(int ac, char **av)
{
	char		*map_string;
	t_map_path	*map_path_d;
	t_end		*map_end;
	t_game		*game;

	map_string = NULL;
	map_path_d = NULL;
	map_end = NULL;
	game = NULL;
	if (ac == 2)
	{
		map_string = ft_map_check(av[1]);
		if (allocate_structs(&map_path_d, &map_end, &game) != 0)
		{
			ft_printf("Memory allocation failed\n");
			return (1);
		}
		f_norminette_2(map_string, map_path_d, map_end, game);
	}
	else
		ft_printf("Add name of the map as argument");
	ft_clean_struct(map_path_d, map_end, game);
	return (0);
}
