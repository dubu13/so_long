/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 19:54:59 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		ft_printf("Error\nNumber of arguments should be 2\n");
		exit(EXIT_FAILURE);
	}
	ft_set(game);
	ft_check_fileformat(argv[1]);
	ft_read_map(argv[1], game);
	ft_map_check(game);
	ft_init(game);
}
