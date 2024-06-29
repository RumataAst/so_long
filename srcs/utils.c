/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:33:44 by akretov           #+#    #+#             */
/*   Updated: 2024/06/06 17:33:08 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_array(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_free_struct_in(t_map_path *m_d, t_end *m_e)
{
	if (m_d)
		free(m_d);
	if (m_e)
		free(m_e);
}

void	ft_clean_struct(t_map_path *m_d, t_end *m_e, t_game *game)
{
	if (game)
	{
		if (game->texture)
		{
			mlx_delete_texture(game->texture);
			game->texture = NULL;
		}
		if (game->img)
		{
			mlx_delete_image(game->mlx, game->img);
			game->img = NULL;
		}
		if (m_e || m_e->emap)
			ft_free_array(m_e->emap);
		if (m_d || m_e)
			ft_free_struct_in(m_d, m_e);
		if (game->mlx)
		{
			mlx_terminate(game->mlx);
			game->mlx = NULL;
		}
		free(game);
	}
	exit (1);
}
