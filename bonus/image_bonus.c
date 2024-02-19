/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:06:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/16 16:29:29 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moves_to_wnd(t_game *game, int c)
{
	char				*str;
	char				*tmp;
	static mlx_image_t	*img = NULL;

	str = ft_itoa(c);
	tmp = ft_strjoin("MOVES: ", str);
	if (img)
		mlx_delete_image(game->mlx_ptr, img);
	img = mlx_put_string(game->mlx_ptr, tmp, 10, 0);
	free(str);
	free(tmp);
}

void	ft_tex_to_img(t_game *game)
{
	game->wall = mlx_texture_to_image(game->mlx_ptr, game->wall_tex);
	if (!game->wall)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->floor = mlx_texture_to_image(game->mlx_ptr, game->floor_tex);
	if (!game->floor)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->player = mlx_texture_to_image(game->mlx_ptr, game->player_tex);
	if (!game->player)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->player_b = mlx_texture_to_image(game->mlx_ptr, game->player_b_tex);
	if (!game->player_b)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->player_l = mlx_texture_to_image(game->mlx_ptr, game->player_l_tex);
	if (!game->player_l)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->player_r = mlx_texture_to_image(game->mlx_ptr, game->player_r_tex);
	if (!game->player_r)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->collectible = mlx_texture_to_image(game->mlx_ptr,
			game->collectible_tex);
	if (!game->collectible)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
	game->exit = mlx_texture_to_image(game->mlx_ptr, game->exit_tex);
	if (!game->exit)
		msg_exit("Error\nIn 'text_to_img'.\n", 1);
}

void	ft_load_png(t_game *game)
{
	game->wall_tex = mlx_load_png(WALL_PNG);
	if (!game->wall_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->floor_tex = mlx_load_png(FLOOR_PNG);
	if (!game->floor_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->player_tex = mlx_load_png(PLAYER_PNG);
	if (!game->player_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->player_b_tex = mlx_load_png(PLAYER_B_PNG);
	if (!game->player_b_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->player_l_tex = mlx_load_png(PLAYER_L_PNG);
	if (!game->player_l_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->player_r_tex = mlx_load_png(PLAYER_R_PNG);
	if (!game->player_r_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->collectible_tex = mlx_load_png(COLLECTIBLE_PNG);
	if (!game->collectible_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	game->exit_tex = mlx_load_png(EXIT_PNG);
	if (!game->exit_tex)
		msg_exit("Error\nIn 'load_png'.\n", 1);
	ft_tex_to_img(game);
}
