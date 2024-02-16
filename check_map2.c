/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:19:23 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/16 20:57:43 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nl(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_temp[i + 1])
	{
		if (game->map_temp[i] == '\n' && game->map_temp[i + 1] == '\n')
			msg_exit("Error\nMap has extra nl.\n", 1);
		i++;
	}
}

int	check_e_c(char **map_copy, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
				//msg_exit("y u do this", 1);
				return (1);
			//else if (map_copy[y][x] != COLLECTIBLE || map_copy[y][x] != EXIT)
			//	return (0);
			x++;
		}
		y++;
	}
	return (0);
}

void	fill_map(char **map_copy, int x, int y)
{
	char	flag;

	flag = 'X';
	if (map_copy[y][x] == WALL || map_copy[y][x] == flag)
		return ;
	map_copy[y][x] = flag;
	fill_map(map_copy, x - 1, y);
	fill_map(map_copy, x + 1, y);
	fill_map(map_copy, x, y - 1);
	fill_map(map_copy, x, y + 1);
}

void	check_validpath(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	fill_map(map_copy, game->p_x, game->p_y);
	if (check_e_c(map_copy, game))
		msg_exit("Error\nUnplayable map.\n", 1);
	//check_e_c(map_copy);
	free_map(map_copy, game->rows);
}
