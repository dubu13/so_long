/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/17 15:30:34 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>

# define IMG_PXL 64
# define WND_NAME "so_long"

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

# define WALL_PNG "./texture/wall.png"
# define FLOOR_PNG "./texture/floor_new.png"
# define PLAYER_PNG "./texture/player.png"
# define PLAYER_B_PNG "./texture/player_b.png"
# define PLAYER_L_PNG "./texture/player_l.png"
# define PLAYER_R_PNG "./texture/player_r.png"
# define COLLECTIBLE_PNG "./texture/collectible.png"
# define EXIT_PNG "./texture/exit.png"

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
	mlx_image_t		*player_b;
	mlx_image_t		*player_l;
	mlx_image_t		*player_r;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_texture_t	*wall_tex;
	mlx_texture_t	*floor_tex;
	mlx_texture_t	*player_tex;
	mlx_texture_t	*player_b_tex;
	mlx_texture_t	*player_l_tex;
	mlx_texture_t	*player_r_tex;
	mlx_texture_t	*collectible_tex;
	mlx_texture_t	*exit_tex;
}					t_game;

// main.c
void		check_map(t_game *game);
void		check_extension(char *argv);
// read_map.c
void		save_map(char *file, t_game *game);
void		file_to_map(t_game *game, int fd);
char		**copy_map(t_game *game);
// check_map.c
void		map_shape(t_game *game);
void		check_elements(t_game *game);
void		check_epc(t_game *game);
void		check_wall(t_game *game);
void		count_epc(t_game *game, int x, int y);
// check_map2.c
void		check_validpath(t_game *game);
void		fill_map(char **map_copy, int x, int y);
int			check_e_c(char **map_copy, t_game *game);
void		check_nl(t_game *game);
// game.c
void		ft_init(t_game *game);
void		move_in_map(t_game *game);
void		ft_img_to_wnd(t_game *game, int y, int x);
void		handle_key(mlx_key_data_t keydata, void *param);
//image.c
void		ft_load_png(t_game *game);
void		ft_tex_to_img(t_game *game);
//bonus
void		moves_to_wnd(t_game *game, int c);
//key_moves.c
void		move_up_down(t_game *game, char direction);
void		move_left_right(t_game *game, char direction);
void		update(t_game *game, int y, int x, char direction);
void		update_collectible(t_game *game, int y, int x);
//player_move.c
void		update_player(t_game *game, int y, int x, char direction);
void		player_up(t_game *game, int x, int y);
void		player_down(t_game *game, int x, int y);
void		player_right(t_game *game, int x, int y);
void		player_left(t_game *game, int x, int y);
// error_free.c
void		free_img_tex(t_game *game);
void		msg_exit(char *msg, int type);
void		free_map(char **map, int rows);

#endif