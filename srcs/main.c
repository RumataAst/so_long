/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:54 by akretov           #+#    #+#             */
/*   Updated: 2024/05/18 17:21:11 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

static void error(void)
{
    puts("Error occurred."); // Change this to an appropriate error message
    exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	if (ac == 2)
	{
		int i = 0;
		int z; // go through line
		int x; // Initialize x here
		int y = 0;	// Initialize x here
		int		fd;
		char	*line;
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
            ft_printf("Nope\n");
			error();
		}
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			z = 0;
			x = 0;
			while (line[z])
			{
			if (line[z] == 'D')
			{
				mlx_texture_t *texture = mlx_load_png("./srcs/door.png");
				if (!texture)
					error();
				mlx_image_t *img = mlx_texture_to_image(mlx, texture);
				if (!img)
					error();
				if (mlx_image_to_window(mlx, img, x, y) < 0)
					error();
				if (x == 0 && y == 0)
				{
					ft_printf("X is %i and Y is %i \n", img->width, img->height);
				}
				y += img->height;
				x += img->width;
			}
			if (line[z] == 'G')
			{
				mlx_texture_t *texture = mlx_load_png("./srcs/goblin.png");
				if (!texture)
					error();
				mlx_image_t *img = mlx_texture_to_image(mlx, texture);
				if (!img)
					error();
				if (mlx_image_to_window(mlx, img, x, y) < 0)
					error();
				y += img->height;
				x += img->width;
			}
			if (line[z] == 'W')
			{
				mlx_texture_t *texture = mlx_load_png("./srcs/wall.png");
				if (!texture)
					error();
				mlx_image_t *img = mlx_texture_to_image(mlx, texture);
				if (!img)
					error();
				if (mlx_image_to_window(mlx, img, x, y) < 0)
					error();	
				y += img->height;
				x += img->width;
			}
			z++;
			}
			i++;
		}
	}
	else
		error();
	mlx_loop(mlx);

    // Clean up resources
    // mlx_delete_image(mlx, img);
    // mlx_delete_texture(mlx, texture);

    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
