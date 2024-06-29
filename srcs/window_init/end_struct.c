/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:51:26 by akretov           #+#    #+#             */
/*   Updated: 2024/06/05 17:17:34 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	f_norminette_3(int i, int j, t_end *end)
{
	end->end_x = j;
	end->end_y = i;
}

void	ft_fill_end(t_end *end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (end->emap[i])
	{
		j = 0;
		while (end->emap[i][j])
		{
			if (end->emap[i][j] == 'P')
			{
				end->start_x = j;
				end->start_y = i;
			}
			if (end->emap[i][j] == 'E')
				f_norminette_3(i, j, end);
			if (end->emap[i][j] == 'C')
				end->collect++;
			j++;
		}
		i++;
	}
}
