/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:43:13 by akretov           #+#    #+#             */
/*   Updated: 2024/06/06 18:57:58 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_is_valid_move(t_game *game, char D, int *new_x, int *new_y)
{
	char	cell;

	*new_x = game->map_end->start_x;
	*new_y = game->map_end->start_y;
	if (D == 'U')
		(*new_y)--;
	else if (D == 'D')
		(*new_y)++;
	else if (D == 'L')
		(*new_x)--;
	else if (D == 'R')
		(*new_x)++;
	else
		return (0);
	if (*new_x < 0 || *new_x >= game->map_info->cols
		|| *new_y < 0 || *new_y >= game->map_info->rows)
		return (0);
	cell = game->map_end->emap[*new_y][*new_x];
	if (cell == '1' || (cell == 'E' && game->map_end->collect != 0))
		return (0);
	return (1);
}

int	ft_execute_move(t_game *game, int new_x, int new_y)
{
	char	cell;

	cell = game->map_end->emap[new_y][new_x];
	if (cell == 'C')
	{
		game->map_end->emap[new_y][new_x] = '0';
		game->map_end->collect--;
	}
	game->map_end->emap[game->map_end->start_y][game->map_end->start_x] = '0';
	game->map_end->start_x = new_x;
	game->map_end->start_y = new_y;
	game->map_end->emap[new_y][new_x] = 'P';
	if (game->map_end->collect == 0)
		ft_put_image_door(game, EXIT_PATH_1);
	return (0);
}

int	ft_valid_move(t_game *game, char D)
{
	int	new_x;
	int	new_y;

	if (!ft_is_valid_move(game, D, &new_x, &new_y))
		return (1);
	return (ft_execute_move(game, new_x, new_y));
}

void	ft_print_movement(t_game *game, char D)
{
	if (ft_valid_move(game, D) == 0)
	{
		if (D == 'U')
			ft_move_up(game);
		if (D == 'D')
			ft_move_down(game);
		if (D == 'L')
			ft_move_left(game);
		if (D == 'R')
			ft_move_right(game);
	}
	if (game->map_end->start_x == game->map_end->end_x
		&& game->map_end->start_y == game->map_end->end_y
		&& game->map_end->collect == 0)
		ft_clean_struct(game->map_info, game->map_end, game);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == 87 || keydata.key == 265)
			ft_print_movement(game, 'U');
		else if (keydata.key == 83 || keydata.key == 264)
			ft_print_movement(game, 'D');
		else if (keydata.key == 65 || keydata.key == 263)
			ft_print_movement(game, 'L');
		else if (keydata.key == 68 || keydata.key == 262)
			ft_print_movement(game, 'R');
		else if (keydata.key == 256)
		{
			ft_printf("%i\n", game->number);
			ft_clean_struct(game->map_info, game->map_end, game);
		}
	}
}
