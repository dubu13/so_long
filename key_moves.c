/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:19 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 21:12:33 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_game *game, int y, int x)
{
	if (game->map[y][x] == EXIT && game->collectible == 0)
		//finish the game
	if (game->map[y][x] == COLLECTIBLE)
	{
		game->map[y][x] = PLAYER;
		game->p_y = y;
		game->p_x = x;
		game->collectible--;
		game->moves++;
	}
	if (game->map[y][x] == FLOOR)
	{
		game->map[y][x] = PLAYER;
		game->p_y = y;
		game->p_x = x;
		game->moves++;
	}
}

void	ft_move_left_right(t_game *game, char direction)
{
	int	y;
	int	x;

	x = game->p_x;
	y = game->p_y;

	if (direction == 'L')
	{
		if (game->map[y][x - 1] == WALL)
			return ;
		ft_move(game, y, x + 1);
		game->map[y][x] = FLOOR;
	}
	if (direction == 'R')
	{
		if (game->map[y][x + 1] == WALL)
			return ;
		ft_move(game, y, x + 1);
		game->map[y][x] = FLOOR;
	}
}

void	ft_move_up_down(t_game *game, char direction)
{
	int	y;
	int	x;

	x = game->p_x;
	y = game->p_y;
	if (direction == 'U')
	{
		if (game->map[y - 1][x] == WALL)
			return ;
		ft_move(game, y - 1, x);
		game->map[y][x] = FLOOR;
	}
	if (direction == 'D')
	{
		if (game->map[y + 1][x] == WALL)
			return ;
		ft_move(game, y + 1, x);
		game->map[y][x] = FLOOR;
	}
}
