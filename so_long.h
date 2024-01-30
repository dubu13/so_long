/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 20:21:38 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "lib_utils/lib_utils.h"
# include <fcntl.h>
# include <unistd.h>

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

typedef struct s_game
{
	void			*mlx_ptr;
	void			*window_ptr;
	char			**map;
	char			**map_copy;
	int				rows;
	int				cols;
	int				p_x;
	int				p_y;
	int				e_x;
	int				e_y;
	int				left_c;
	int				check_p;
	int				check_c;
	int				check_e;
	int				moves;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*collectible_t;
	mlx_texture_t	*exit_t;
}					t_game;

// so_long.c
void		ft_set(t_game *game);
// check.c
void		ft_check_fileformat(char *argv);
void		ft_read_map(char *file, t_game *game);
// map.c
void		ft_map_check(t_game *game);
void		ft_map_shape(t_game *game);
void		ft_check_elements(t_game *game);
void		ft_check_epc(t_game *game);
void		ft_check_wall(t_game *game);
// game.c
void		ft_init(t_game *game);
void		ft_move_in_map(t_game *game);
void		ft_handle_key(mlx_key_data_t keydata, void *param);
//image.c
void		ft_pass_texture(t_game *game);
void		ft_texture_wnd(t_game *game);
void		ft_pass_to_wnd(t_game *game, int x, int y);
//key_moves
void		ft_move_up_down(t_game *game, char direction);
void		ft_move_left_right(t_game *game, char direction);
void		ft_move(t_game *game, int y, int x);
// utils.c
int			ft_open_file(char *file);
void		ft_update(t_game *game, int x, int y);
// error_free.c
void		ft_free_mapcopy(t_game *game);
void		ft_msg_exit(char *msg, int type);

#endif