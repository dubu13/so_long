/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:20:20 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/17 00:25:39 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != 'WALL' || \
			game->map[i][game->cols - 1] != 'WALL')
			ft_printf("Error\nWall is missing.\n");
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != 'WALL' || \
			game->map[0][game->rows - 1] != 'WALL')
			ft_printf("Error\nWall is missing.\n");
	}
	i++;
}

void	ft_check_epc(t_game *game)
{
	if (game->exit != 1)
		ft_printf("Map should contain be 1 exit!\n");
	if (game->player != 1)
		ft_printf("Map should contain 1 player!\n");
	if (game->collectible < 1)
		ft_printf("Map should contain least 1 collectible!");
}

void	ft_check_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < game->rows)
	{
		while (x < game->cols)
		{
			if (!ft_strchr("01CEP", game->map[y][x]))
				ft_printf("Error\nMap should only contain 0, 1, C, E, P\n");
			else if (game->map[y][x] == PLAYER)
				ft_update(game->map, x, y);
			else if (game->map[y][x] == COLLECTIBLE)
				ft_update(game->map, x, y);
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

	max_len = ft_strlen(game->map_copy[y]);

	while (y < game->rows)
	{
		x = ft_strlen(game->map_copy[y]);
		if (max_len != x)
		{
			ft_printf("Map should be rectangle.");
			exit(EXIT_FAILURE);
		}
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
