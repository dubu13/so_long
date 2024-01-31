/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/31 18:08:24 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_temp;

	line = ft_calloc(1, sizeof(char));
	map_temp = ft_calloc(1, sizeof(char));
	fd = ft_open_file(file);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
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
	game->map = ft_split(map_temp, '\n');
	if (!game->map)
		ft_free_mapcopy(game);
	free(map_temp);
}

void	ft_check_fileformat(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e' \
		|| file[len - 3] != 'b' || file[len - 4] != '.')
		ft_msg_exit("Error\nMap should be in '.ber' format.\n", 1);
}

void	ft_set(t_game *game)
{
	game->player = 0;
	game->collectible = 0;
	game->exit = 0;
	game->moves = 0;
	game->rows = 0;
	game->cols = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		ft_msg_exit("Error\nNumber of arguments should be 2\n", 1);
	ft_set(game);
	ft_check_fileformat(argv[1]);
	ft_read_map(argv[1], game);
	ft_map_check(game);
	ft_init(game);
	ft_free_img_tex(game);
	ft_free_map(game);
	mlx_terminate(game->mlx_ptr);
	exit(EXIT_SUCCESS);
}
