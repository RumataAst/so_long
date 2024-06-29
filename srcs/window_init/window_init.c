/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:13:19 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 17:17:36 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_end_init(t_end *end, char *map_str)
{
	end->emap = ft_split(map_str, '\n');
	end->start_x = 0;
	end->start_y = 0;
	end->end_x = 0;
	end->end_y = 0;
	end->collect = 0;
}

void	ft_map_path_init(t_map_path *path)
{
	path->rows = 0;
	path->cols = 0;
	path->pl_x = 0;
	path->pl_y = 0;
	path->exit_x = 0;
	path->exit_y = 0;
}

void	ft_init(t_game *game, t_map_path *map_path_d, t_end *end)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "GAME", true);
	if (!game->mlx)
		ft_clean_struct(map_path_d, end, game);
	game->map_end = NULL;
	game->texture = NULL;
	game->img = NULL;
	game->map_info = map_path_d;
	game->map_end = end;
	game->x = WIDTH / 3;
	game->y = HEIGHT / 3;
	game->number = 0;
	game->cur_x = 0;
	game->cur_y = 0;
	game->end_x = 0;
	game->end_y = 0;
}
