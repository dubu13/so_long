/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/17 00:26:10 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	**map_temp;

	game->rows = 0;
	fd = ft_open_file(file);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_temp = ft_strjoin_gnl(map_temp, line);
		free(line);
		if (!map_temp)
		{
			free(map_temp);
			exit(EXIT_FAILURE);
		}
		game->rows++;
	}
	game->map_copy = ft_split(map_temp, '\n');
	if (!game->map_copy)
		ft_free(game->map_copy);
	free(map_temp);
}

void	ft_file_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e' \
		|| file[len - 3] != 'b' || file[len - 4] != '.')
	{
		ft_printf("Error\nFile should be end with '.ber'\n");
		exit(1);
	}
}

