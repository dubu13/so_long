/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:20:20 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/31 16:41:34 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != WALL || \
			game->map[i][game->cols - 1] != WALL)
			ft_msg_exit("Error\nWall is missing.\n", 1);
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != WALL || \
			game->map[0][game->rows - 1] != WALL)
			ft_msg_exit("Error\nWall is missing.\n", 1);
	}
	i++;
}

void	ft_check_epc(t_game *game)
{
	if (game->check_e != 1)
		ft_msg_exit("Error\nMap should contain be 1 exit!\n", 1);
	if (game->check_p != 1)
		ft_msg_exit("Error\nMap should contain 1 player!\n", 1);
	if (game->check_c < 1)
		ft_msg_exit("Error\nMap should contain least 1 collectible!\n", 1);
}

void	ft_check_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!ft_strchr("01CEP", game->map[y][x]))
				ft_msg_exit("Error\nMap should only contain 0,1,C,E,P\n", 1);
			else if (game->map[y][x] == PLAYER)
				ft_count_epc(game, y, x);
			else if (game->map[y][x] == COLLECTIBLE)
				ft_count_epc(game, y, x);
			else if (game->map[y][x] == EXIT)
				ft_count_epc(game, y, x);
			x++;
		}
		y++;
	}
}

void	ft_map_shape(t_game *game)
{
	int	x;
	int	y;
	int	max_len;

	y = game->cols;
	x = 0;
	max_len = ft_strlen(game->map[y]);
	while (y < game->rows)
	{
		x = ft_strlen(game->map[y]);
		if (max_len != x)
			ft_msg_exit("Error\nMap should be rectangle.\n", 1);
		y++;
	}
	game->cols = max_len;
}

void	ft_map_check(t_game *game)
{
	ft_map_shape(game);
	ft_check_elements(game);
	ft_check_epc(game);
	ft_check_wall(game);
}
