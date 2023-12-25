/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/12/25 20:24:23 by dhasan           ###   ########.fr       */
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

void	ft_check_map2(t_game *game)
{
	if (game->exit != 1)
		ft_printf("Map should contain be 1 exit!\n");
	if (game->player != 1)
		ft_printf("Map should contain 1 player!\n");
	if (game->collectible < 1)
		ft_printf("Map should contain least 1 collectible!");
}

void	ft_check_map(t_game *game)
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

void	ft_check_file(char *argv)
{
	int	fd;
	int	len;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile doesn't exist\n");
		close(fd);
		exit(1);
	}
	len = ft_strlen(argv);
	if (argv[len - 1] != 'r' || argv[len - 2] != 'e' \
		|| argv[len - 3] != 'b' || argv[len - 4] != '.')
	{
		ft_printf("Error\nFile should be end with '.ber'\n");
		exit(1);
	}
	close(fd);
}
