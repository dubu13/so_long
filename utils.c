/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:34:36 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 20:16:12 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//should i close it first or later??
int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_msg_exit("Error\nFailed to open map file.\n", 1);
	}
	close(fd);
	return (fd);
}

void	ft_update(t_game *game, int x, int y)
{
	if (game->map[y][x] == PLAYER)
	{
		game->check_p++;
		game->p_x = x;
		game->p_y = y;
	}
	if (game->map[y][x] == COLLECTIBLE)
		game->check_c++;
	if (game->map[y][x] == EXIT)
		game->check_e++;
}
