/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:34:36 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/16 23:21:26 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open map file.");
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	return (fd);
}

void	ft_update(t_game *game, int x, int y)
{
	if (game->map[x][y] == PLAYER)
	{
		game->player++;
		game->p_x = x;
		game->p_y = y;
	}
	if (game->map[x][y] == COLLECTIBLE)
		game->collectible++;
	if (game->map[x][y] == EXIT)
		game->exit++;
}
