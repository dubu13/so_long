/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:19 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/15 20:02:18 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_collectible(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->count_c)
	{
		if (game->collectible->instances[i].x == x * IMG_PXL
			&& game->collectible->instances[i].y == y * IMG_PXL)
		{
			game->collectible->instances[i].enabled = false;
			game->left_c--;
			break ;
		}
		i++;
	}
}

void	update_player(t_game *game, int y, int x)
{
	if (game->map[y][x] != EXIT)
		game->map[y][x] = PLAYER;
	game->p_y = y;
	game->p_x = x;
	game->player->instances->x = game->p_x * IMG_PXL;
	game->player->instances->y = game->p_y * IMG_PXL;
}

void	update(t_game *game, int y, int x)
{
	if (game->map[y][x] == EXIT && game->left_c == 0)
	{
		game->moves++;
		free_map(game->map, game->rows);
		msg_exit("Congratulation!\nYou finished the game\n", 0);
	}
	if (game->map[y][x] == COLLECTIBLE)
	{
		update_collectible(game, y, x);
		update_player(game, y, x);
		game->moves++;
	}
	else
	{
		update_player(game, y, x);
		game->moves++;
	}
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Collectibles left: %d\n", game->left_c);
	moves_to_wnd(game, game->moves);
}

void	move_left_right(t_game *game, char direction)
{
	if (direction == 'L')
	{
		if (game->map[game->p_y][game->p_x - 1] == WALL)
			return ;
		update(game, game->p_y, game->p_x - 1);
	}
	if (direction == 'R')
	{
		if (game->map[game->p_y][game->p_x + 1] == WALL)
			return ;
		update(game, game->p_y, game->p_x + 1);
	}
}

void	move_up_down(t_game *game, char direction)
{
	if (direction == 'U')
	{
		if (game->map[game->p_y - 1][game->p_x] == WALL)
			return ;
		update(game, game->p_y - 1, game->p_x);
	}
	if (direction == 'D')
	{
		if (game->map[game->p_y + 1][game->p_x] == WALL)
			return ;
		update(game, game->p_y + 1, game->p_x);
	}
}
