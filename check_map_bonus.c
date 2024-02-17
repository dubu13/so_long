/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:20:20 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/17 15:24:55 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != WALL ||
			game->map[i][game->cols - 1] != WALL)
			msg_exit("Error\nMissing Wall in first or last column.\n", 1);
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != WALL ||
			game->map[game->rows - 1][i] != WALL)
			msg_exit("Error\nMissing Wall in first or last row.\n", 1);
		i++;
	}
}

void	check_epc(t_game *game)
{
	if (game->count_e != 1)
		msg_exit("Error\nMap should contain 1 exit!\n", 1);
	if (game->count_p != 1)
		msg_exit("Error\nMap should contain 1 player!\n", 1);
	if (game->count_c < 1)
		msg_exit("Error\nMap should contain least 1 collectible!\n", 1);
}

void	count_epc(t_game *game, int y, int x)
{
	if (game->map[y][x] == PLAYER)
	{
		game->count_p++;
		game->p_x = x;
		game->p_y = y;
	}
	if (game->map[y][x] == COLLECTIBLE)
		game->count_c++;
	if (game->map[y][x] == EXIT)
		game->count_e++;
}

void	check_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!ft_strchr("01CEP", game->map[y][x]))
				msg_exit("Error\nMap should only contain 0,1,C,E,P.\n", 1);
			else if (game->map[y][x] == PLAYER)
				count_epc(game, y, x);
			else if (game->map[y][x] == COLLECTIBLE)
				count_epc(game, y, x);
			else if (game->map[y][x] == EXIT)
				count_epc(game, y, x);
			x++;
		}
		y++;
	}
}

void	map_shape(t_game *game)
{
	int	x;
	int	y;
	int	max_len;

	y = 0;
	x = 0;
	max_len = ft_strlen(game->map[y]);
	while (y < game->rows)
	{
		x = ft_strlen(game->map[y]);
		if (max_len != x)
			msg_exit("Error\nMap should be rectangle.\n", 1);
		y++;
	}
	game->cols = max_len;
}
