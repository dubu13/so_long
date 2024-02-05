/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/05 22:52:37 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/inc/libft.h"
# include <fcntl.h>
# include <unistd.h>

# define IMG_PXL 64
# define WND_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define WALL_PNG "./texture/wall.png"
# define FLOOR_PNG "./texture/floor.png"
# define PLAYER_PNG "./texture/reaper.png"
# define COLLECTIBLE_PNG "./texture/soul.png"
# define EXIT_PNG "./texture/exit.png"

typedef struct s_collectibles
{
	int	x;
	int	y;
}				t_collectibles;

typedef struct s_game
{
	void			*mlx_ptr;
	char			**map;
	char			*map_temp;
	int				rows;
	int				cols;
	int				p_x;
	int				p_y;
	int				left_c;
	int				count_p;
	int				count_c;
	int				count_e;
	int				moves;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*player_tex;
	mlx_texture_t	*collectible_tex;
	mlx_texture_t	*exit_tex;
	t_collectibles	*collectibles;
}					t_game;

// void		print_map(t_game *game);
// so_long.c
void		check_map(t_game *game);
void		check_extension(char *argv);
// read_map.c
void		save_map(char *file, t_game *game);
void		file_to_map(t_game *game, int fd);
// check_map.c
void		count_epc(t_game *game, int x, int y);
void		map_shape(t_game *game);
void		check_elements(t_game *game);
void		check_epc(t_game *game);
void		check_wall(t_game *game);
// game.c
void		ft_init(t_game *game);
void		move_in_map(t_game *game);
void		handle_key(mlx_key_data_t keydata, void *param);
//image.c
void		ft_load_png(t_game *game);
void		ft_tex_to_img(t_game *game);
void		ft_img_to_wnd(t_game *game, int x, int y);
//key_moves.c
void		move_up_down(t_game *game, char direction);
void		move_left_right(t_game *game, char direction);
void		update(t_game *game, int y, int x);
// error_free.c
void		free_map(t_game *game);
void		msg_exit(char *msg, int type);
void		free_img_tex(t_game *game);

#endif