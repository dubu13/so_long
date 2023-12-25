/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/12/25 20:57:52 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib_utils/lib_utils.h"
# include <unistd.h>
# include <fcntl.h>
# include "./MLX42/INCLUDE/MLX42/MLX42.h"

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define WALL_PNG './texture/'
# define FLOOR_PNG './texture/floor.png'
# define PLAYER_PNG './texture/reaper.png'
# define COLLECTIBLE_PNG './texture/soul.png'
# define EXIT_PNG './texture/'

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
	int		rows;
	int		cols;
	int		player;
	int		collectible;
	int		exit;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		movements;
	int		lenght;
	int		width;
}					t_game;

#endif