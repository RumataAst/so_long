/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:53:05 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 17:19:08 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_move_up(t_game *game)
{
	ft_put_image(game, FLOOR_PATH);
	game->y -= 32;
	ft_put_image(game, FLOOR_PATH);
	ft_put_image(game, PLAYER_PATH);
	game->number++;
	ft_printf("%i\n", game->number);
}

void	ft_move_down(t_game *game)
{
	ft_put_image(game, FLOOR_PATH);
	game->y += 32;
	ft_put_image(game, FLOOR_PATH);
	ft_put_image(game, PLAYER_PATH);
	game->number++;
	ft_printf("%i\n", game->number);
}

void	ft_move_left(t_game *game)
{
	ft_put_image(game, FLOOR_PATH);
	game->x -= 32;
	ft_put_image(game, FLOOR_PATH);
	ft_put_image(game, PLAYER_PATH_L);
	game->number++;
	ft_printf("%i\n", game->number);
}

void	ft_move_right(t_game *game)
{
	ft_put_image(game, FLOOR_PATH);
	game->x += 32;
	ft_put_image(game, FLOOR_PATH);
	ft_put_image(game, PLAYER_PATH);
	game->number++;
	ft_printf("%i\n", game->number);
}
