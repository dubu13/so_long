/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:19:23 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/13 22:43:53 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>
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
	if (map_copy[y][x] == WALL || map_copy[y][x] == '8')
		return ;
	map_copy[y][x] = '8';
	// printf("d\n");
	fill_map(map_copy, x - 1, y);
	fill_map(map_copy, x + 1, y);
	fill_map(map_copy, x, y - 1);
	fill_map(map_copy, x, y + 1);
}

void	check_validpath(t_game *game)
{
	char	**map_copy;
	int		x;
	int		y;
	int		rows;

	x = game->p_x;
	y = game->p_y;
	map_copy = copy_map(game);
	fill_map(map_copy, x, y);
	if (check_e_c(map_copy))
		msg_exit("Unplayable map\n", 1);
	rows = game->rows;
	free_copy(map_copy, rows);
}
