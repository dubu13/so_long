/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/17 00:26:57 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib_utils/lib_utils.h"
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

# define IMG_HEIGHT 50
# define IMG_WIDTH 50
# define IMG_PXL 64
# define WND_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define WALL_PNG "./texture/wall2.png/"
# define FLOOR_PNG "./texture/floor.png"
# define PLAYER_PNG "./texture/reaper.png"
# define COLLECTIBLE_PNG "./texture/soul.png"
# define EXIT_PNG "./texture/close.png"

typedef struct s_image
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
}						t_image;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window_ptr;
	char	**map;
	char	*map_copy;
	int		rows;
	int		cols;
	int		player;
	int		collectible;
	int		exit;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		moves;
	int		height;
	int		width;
}					t_game;

//so_long.c
void	ft_set(t_game *game);
//image.c
void	ft_pass_texture(t_image *image, t_game *game);
//game.c
void	ft_init(t_game *game);
void	ft_handle_key(int key_input, t_game *game);
//check.c
void	ft_file_name(char *argv);
void	ft_read_map(char *file, t_game *game);
//map.c
void	ft_map_shape(t_game *game);
void	ft_check_elements(t_game *game);
void	ft_check_epc(t_game *game);
void	ft_check_wall(t_game *game);
//utils.c
void	ft_update(t_game *game, int x, int y);

#endif