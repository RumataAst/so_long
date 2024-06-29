/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:28 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:39:45 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_e_c_p(char *map)
{
	int	i;
	int	e_count;
	int	c_count;
	int	p_count;

	i = 0;
	e_count = 0;
	c_count = 0;
	p_count = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			e_count++;
		if (map[i] == 'C')
			c_count++;
		if (map[i] == 'P')
			p_count++;
		i++;
	}
	if (e_count != 1 || c_count < 1 || p_count != 1)
		return (1);
	return (0);
}

int	ft_check_letter(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1'
			&& map[i] != 'C' && map[i] != 'E'
			&& map[i] != '\n' && map[i] != 'P')
			return (1);
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_map_size(int fd)
{
	char	*line;
	int		i;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
		{
			i++;
			count++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	*ft_read_to_buf(int fd, int map_size)
{
	char	*map;
	char	*line;
	int		i;
	int		j;

	j = 0;
	map = (char *)malloc(sizeof(char) * map_size + 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
			map[j++] = line[i++];
		free(line);
		line = get_next_line(fd);
	}
	map[j] = '\0';
	return (map);
}

char	*ft_check_rules(int fd, char *map_name)
{
	char	*map;
	int		map_size;
	int		new_fd;

	map_size = ft_map_size(fd);
	new_fd = open(map_name, O_RDONLY);
	map = ft_read_to_buf(new_fd, map_size);
	if (ft_check_letter(map) != 0
		|| ft_check_e_c_p(map) != 0
		|| ft_check_rec(map) != 0
		|| ft_check_walls(map) != 0)
	{
		free(map);
		ft_error_free_name(map_name, "Map is incorrect", 4, new_fd);
	}
	free(map_name);
	return (map);
}
