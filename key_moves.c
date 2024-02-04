/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:19 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/04 16:24:28 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int y, int x)
{
	if (game->map[y][x] == EXIT && game->left_c == 0)
	{
		free_map(game);
		msg_exit("Congratulation!\n", 0);
	}
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = PLAYER;
		game->p_y = y;
		game->p_x = x;
		game->left_c--;
		game->moves++;
		game->player->instances[0].x = x * 64;
		game->player->instances[0].y = y * 64;
	}
	if (game->map[y][x] == FLOOR)
	{
		game->map[y][x] = PLAYER;
		game->p_y = y;
		game->p_x = x;
		game->moves++;
		game->player->instances[0].x = x * 64;
		game->player->instances[0].y = y * 64;
	}
}

void	move_left_right(t_game *game, char direction)
{
	int	y;
	int	x;

	x = game->p_x;
	y = game->p_y;
	if (direction == 'L')
	{
		if (game->map[y][x - 1] == WALL)
			return ;
		update(game, y, x - 1);
	}
	if (direction == 'R')
	{
		if (game->map[y][x + 1] == WALL)
			return ;
		update(game, y, x + 1);
	}
}

void	move_up_down(t_game *game, char direction)
{
	int	y;
	int	x;

	x = game->p_x;
	y = game->p_y;
	if (direction == 'U')
	{
		if (game->map[y - 1][x] == WALL)
			return ;
		update(game, y - 1, x);
	}
	if (direction == 'D')
	{
		if (game->map[y + 1][x] == WALL)
			return ;
		update(game, y + 1, x);
	}
}
