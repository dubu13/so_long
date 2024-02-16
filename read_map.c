/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:16:27 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/16 19:38:10 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**copy;
	int		y;

	copy = ft_calloc(game->rows, sizeof(char *));
	if (!copy)
		msg_exit("Error\nMemory allocation failed.\n", 1);
	y = 0;
	while (y < game->rows)
	{
		copy[y] = ft_strdup(game->map[y]);
		if (!copy[y])
			msg_exit("Error\nMemory allocation failed.\n", 1);
		y++;
	}
	return (copy);
}

void	file_to_map(t_game *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		msg_exit("Error\nFile is empty.\n", 1);
	if (line[0] == '\n')
		msg_exit("Error\nMap starting w nl.\n", 1);
	while (line)
	{
		game->map_temp = ft_strjoin_gnl(game->map_temp, line);
		free(line);
		if (!game->map_temp)
			msg_exit("Error in 'file_to_map'.\n", 1);
		game->rows++;
		line = get_next_line(fd);
	}
}

void	save_map(char *file, t_game *game)
{
	int	fd;

	game->map_temp = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		msg_exit("Error\nFailed to open map file.\n", 1);
	file_to_map(game, fd);
	close(fd);
	check_nl(game);
	game->map = ft_split(game->map_temp, '\n');
	if (!game->map)
	{
		free_map(game->map, game->rows);
		msg_exit("Error in 'save_map'.\n", 1);
	}
	free(game->map_temp);
}
