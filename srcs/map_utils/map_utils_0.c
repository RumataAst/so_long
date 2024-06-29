/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:53:14 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:38:49 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_error_free_name(char *map_name, char *e_mes, int i, int fd)
{
	free(map_name);
	close(fd);
	perror(e_mes);
	exit(i);
}

int	ft_read_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_error_free_name(map_name, "File wasn't opened ", 1, fd);
	return (fd);
}

char	*ft_map_name(char *av)
{
	int		len;
	char	*map;

	len = ft_strlen(av);
	map = NULL;
	if (len >= 4 && strcmp(av + len - 4, ".ber") == 0)
	{
		map = (char *)malloc(sizeof(char) * (len + 1));
		if (map == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		ft_strlcpy(map, av, len + 1);
	}
	else
	{
		perror("Name is incorrect");
		exit(EXIT_FAILURE);
	}
	return (map);
}

char	*ft_map_check(char *av)
{
	char	*map_name;
	int		fd;
	char	*map;

	map_name = (char *)ft_map_name(av);
	fd = ft_read_map(map_name);
	map = ft_check_rules(fd, map_name);
	close(fd);
	return (map);
}
