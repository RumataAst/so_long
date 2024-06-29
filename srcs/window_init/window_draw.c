/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:30:56 by akretov           #+#    #+#             */
/*   Updated: 2024/06/06 17:34:29 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_correct_sprite(char l, t_game *game)
{
	if (l == '1')
		ft_put_image(game, WALL_PATH);
	else if (l == '0')
		ft_put_image(game, FLOOR_PATH);
	else if (l == 'P')
	{
		ft_put_image(game, FLOOR_PATH);
		ft_put_image(game, PLAYER_PATH);
	}
	else if (l == 'C')
	{
		ft_put_image(game, FLOOR_PATH);
		ft_put_image(game, COLLECT_PATH);
	}
	else if (l == 'E')
	{
		game->end_x = game->x;
		game->end_y = game->y;
		ft_put_image(game, WALL_PATH);
		ft_put_image(game, EXIT_PATH);
	}
}

void	ft_put_image(t_game *game, char *sprite)
{
	game->texture = mlx_load_png(sprite);
	if (!game->texture)
	{
		perror("texture");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	if (!game->img)
	{
		perror("image");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
	if (game->texture)
	{
		mlx_delete_texture(game->texture);
		game->texture = NULL;
	}
	if (mlx_image_to_window(game->mlx, game->img, game->x, game->y) < 0)
	{
		perror("window");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
}

void	ft_put_image_door(t_game *game, char *sprite)
{
	game->texture = mlx_load_png(sprite);
	if (!game->texture)
	{
		perror("texture");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
	game->img = mlx_texture_to_image(game->mlx, game->texture);
	if (!game->img)
	{
		perror("image");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
	if (game->texture)
	{
		mlx_delete_texture(game->texture);
		game->texture = NULL;
	}
	if (mlx_image_to_window(game->mlx, game->img, game->end_x, game->end_y) < 0)
	{
		perror("window");
		ft_clean_struct(game->map_info, game->map_end, game);
		exit (1);
	}
}

void	ft_draw(char *map_string, t_game *game)
{
	size_t	i;

	i = 0;
	while (map_string[i])
	{
		if (map_string[i] == 'P')
		{
			game->cur_x = game->x;
			game->cur_y = game->y;
		}
		if (map_string[i] == '\n')
		{
			game->y += 32;
			game->x = WIDTH / 3;
		}
		else
		{
			ft_correct_sprite(map_string[i], game);
			game->x += 32;
		}
		i++;
	}
}
