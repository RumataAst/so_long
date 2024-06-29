/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:00:50 by akretov           #+#    #+#             */
/*   Updated: 2024/06/07 17:33:00 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libraries
# include <../MLX/include/MLX42/MLX42.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/get_next_line_bonus.h"
# include "../libft/include/ft_printf.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>

# define WIDTH 1400
# define HEIGHT 1000
# define EXIT_PATH "./sprites/textures/door_0.png"
# define EXIT_PATH_1 "./sprites/textures/door_5.png"
# define PLAYER_PATH "./sprites/char/lancelot_def.png"
# define PLAYER_PATH_L "./sprites/char/lancelot_left.png"
# define COLLECT_PATH "./sprites/collect/key.png"
# define WALL_PATH "./sprites/textures/wall.png"
# define FLOOR_PATH "./sprites/textures/floor.png"
# define MAX_SIZE 100

//Structs
typedef struct s_path
{
	char	map[MAX_SIZE][MAX_SIZE];
	int		rows;
	int		cols;
	int		pl_x;
	int		pl_y;
	int		exit_x;
	int		exit_y;
}	t_map_path;

typedef struct s_map_end
{
	char	**emap;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		collect;
}	t_end;

typedef struct s_main_game
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	t_map_path		*map_info;
	t_end			*map_end;
	int				x;
	int				y;
	int				cur_x;
	int				cur_y;
	int				end_x;
	int				end_y;
	size_t			number;
}	t_game;

// Mine functions

// map_utils_0.c
int		ft_check_name(char *av);
void	ft_error_free_name(char *map_name, char *e_mes, int i, int fd);
char	*ft_map_name(char *av);
int		ft_read_map(char *map_name);
char	*ft_map_check(char *av);

// map_utils_1.c
int		ft_check_e_c_p(char *map);
int		ft_check_letter(char *map);
int		ft_map_size(int fd);
char	*ft_read_to_buf(int fd, int map_size);
char	*ft_check_rules(int fd, char *map_name);

// map_utils_2
int		ft_check_rec(char *map);

// map_utils_3
int		ft_check_walls(char *map);

//map_path.c
void	ft_map_path(char *map_string, t_map_path *map_path);
int		ft_flood_fill(t_map_path *map_path, int x, int y);

//window_draw.c
void	ft_correct_sprite(char l, t_game *game);
void	ft_put_image(t_game *game, char *sprite);
void	ft_put_image_door(t_game *game, char *sprite);
void	ft_draw(char *map_string, t_game *game);

//window_init.c
void	ft_end_init(t_end *end, char *map);
void	ft_map_path_init(t_map_path *path);
void	ft_init(t_game *game, t_map_path *map_path_d, t_end *end);

//end_struct.c
void	ft_fill_end(t_end *end);

//movement.c
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

//hook.c
int		ft_is_valid_move(t_game *game, char D, int *new_x, int *new_y);
int		ft_execute_move(t_game *game, int new_x, int new_y);
int		ft_valid_move(t_game *game, char D);
void	my_keyhook(mlx_key_data_t keydata, void *param);

//utils.c
void	ft_clean_struct(t_map_path *m_d, t_end *m_e, t_game *game);

//run_game.c
void	ft_run_game(char *map, t_game *game, t_map_path *path_st, t_end *end);

#endif