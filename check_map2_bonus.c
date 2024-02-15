/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:19:23 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/15 19:59:18 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_e_c(char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == COLLECTIBLE || map_copy[y][x] == EXIT)
				return (1);
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
	if (check_e_c(map_copy))
		msg_exit("Error\nUnplayable map.\n", 1);
	free_map(map_copy, game->rows);
}
