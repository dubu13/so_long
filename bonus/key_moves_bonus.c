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

void	update(t_game *game, int y, int x, char direction)
{
	if (game->map[y][x] == EXIT && game->left_c == 0)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		moves_to_wnd(game, game->moves);
		free_map(game->map, game->rows);
		msg_exit("Congratulation!\nYou Finished The Game.\n", 0);
	}
	if (game->map[y][x] == COLLECTIBLE)
	{
		update_collectible(game, y, x);
		update_player(game, y, x, direction);
		game->moves++;
		ft_printf("Collectibles left: %d\n", game->left_c);
	}
	else
	{
		update_player(game, y, x, direction);
		game->moves++;
	}
	ft_printf("Moves: %d\n", game->moves);
	moves_to_wnd(game, game->moves);
}

void	move_left_right(t_game *game, char direction)
{
	if (direction == 'L')
	{
		if (game->map[game->p_y][game->p_x - 1] == WALL)
			return ;
		update(game, game->p_y, game->p_x - 1, direction);
	}
	if (direction == 'R')
	{
		if (game->map[game->p_y][game->p_x + 1] == WALL)
			return ;
		update(game, game->p_y, game->p_x + 1, direction);
	}
}

void	move_up_down(t_game *game, char direction)
{
	if (direction == 'U')
	{
		if (game->map[game->p_y - 1][game->p_x] == WALL)
			return ;
		update(game, game->p_y - 1, game->p_x, direction);
	}
	if (direction == 'D')
	{
		if (game->map[game->p_y + 1][game->p_x] == WALL)
			return ;
		update(game, game->p_y + 1, game->p_x, direction);
	}
}
