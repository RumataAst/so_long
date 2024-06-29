/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:55 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:29:10 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_run_game(char *map, t_game *game, t_map_path *path_st, t_end *end)
{
	ft_init(game, path_st, end);
	ft_draw(map, game);
	ft_fill_end(end);
	game->x = game->cur_x;
	game->y = game->cur_y;
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
}
