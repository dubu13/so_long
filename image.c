/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:06:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 19:52:22 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pass_to_wnd(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map_copy[y][x];
	if (pos == FLOOR)
		mlx_image_to_window(game->mlx_ptr, game->floor, x * 64, y * 64);
	else if (pos == WALL)
		mlx_image_to_window(game->mlx_ptr, game->wall, x * 64, y * 64);
	else if (pos == COLLECTIBLE)
		mlx_image_to_window(game->mlx_ptr, game->collectible, x * 64, y * 64);
	else if (pos == EXIT)
		mlx_image_to_window(game->mlx_ptr, game->collectible, x * 64, y * 64);
	if (pos == PLAYER)
		mlx_image_to_window(game->mlx_ptr, game->player, x * 64, y * 64);
}

void	ft_texture_wnd(t_game *game)
{
	game->wall = mlx_texture_to_image(game->mlx_ptr, game->wall_t);
	if (!game->wall)
		ft_msg_exit("Error\n", 1);
	game->floor = mlx_texture_to_image(game->mlx_ptr, game->floor_t);
	if (!game->floor)
		ft_msg_exit("Error\n", 1);
	game->player = mlx_texture_to_image(game->mlx_ptr, game->player_t);
	if (!game->player)
		ft_msg_exit("Error\n", 1);
	game->collectible = mlx_texture_to_image(game->mlx_ptr,
			game->collectible_t);
	if (!game->collectible)
		ft_msg_exit("Error\n", 1);
	game->exit = mlx_texture_to_image(game->mlx_ptr, game->exit_t);
	if (!game->exit)
		ft_msg_exit("Error\n", 1);
}

void	ft_pass_texture(t_game *game)
{
	game->wall_t = mlx_load_png(WALL_PNG);
	if (!game->wall_t)
		ft_msg_exit("Error\n", 1);
	game->floor_t = mlx_load_png(FLOOR_PNG);
	if (!game->floor_t)
		ft_msg_exit("Error\n", 1);
	game->player_t = mlx_load_png(PLAYER_PNG);
	if (!game->player_t)
		ft_msg_exit("Error\n", 1);
	game->collectible_t = mlx_load_png(COLLECTIBLE_PNG);
	if (!game->collectible_t)
		ft_msg_exit("Error\n", 1);
	game->exit_t = mlx_load_png(EXIT_PNG);
	if (!game->exit_t)
		ft_msg_exit("Error\n", 1);
	ft_texture_wnd(game);
}
