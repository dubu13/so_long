/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:19 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/17 15:22:12 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_player(t_game *game, int y, int x, char direction)
{
	if (game->map[y][x] != EXIT)
		game->map[y][x] = PLAYER;
	game->p_y = y;
	game->p_x = x;
	if (direction == 'U')
		player_up(game, x, y);
	if (direction == 'L')
		player_left(game, x, y);
	if (direction == 'R')
		player_right(game, x, y);
	if (direction == 'D')
		player_down(game, x, y);
}

void	player_up(t_game *game, int x, int y)
{
	game->player_b->instances[0].enabled = true;
	game->player_b->instances[0].x = x * IMG_PXL;
	game->player_b->instances[0].y = y * IMG_PXL;
	game->player->instances[0].enabled = false;
	game->player_l->instances[0].enabled = false;
	game->player_r->instances[0].enabled = false;
}

void	player_left(t_game *game, int x, int y)
{
	game->player_l->instances[0].enabled = true;
	game->player_l->instances[0].x = x * IMG_PXL;
	game->player_l->instances[0].y = y * IMG_PXL;
	game->player->instances[0].enabled = false;
	game->player_b->instances[0].enabled = false;
	game->player_r->instances[0].enabled = false;
}

void	player_right(t_game *game, int x, int y)
{
	game->player_r->instances[0].enabled = true;
	game->player_r->instances[0].x = x * IMG_PXL;
	game->player_r->instances[0].y = y * IMG_PXL;
	game->player->instances[0].enabled = false;
	game->player_l->instances[0].enabled = false;
	game->player_b->instances[0].enabled = false;
}

void	player_down(t_game *game, int x, int y)
{
	game->player->instances[0].enabled = true;
	game->player->instances[0].x = x * IMG_PXL;
	game->player->instances[0].y = y * IMG_PXL;
	game->player_b->instances[0].enabled = false;
	game->player_l->instances[0].enabled = false;
	game->player_r->instances[0].enabled = false;
}
