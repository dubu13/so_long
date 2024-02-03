/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/03 19:45:16 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	map_shape(game);
	check_elements(game);
	check_epc(game);
	check_wall(game);
}

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] != 'r' || file[len - 2] != 'e' \
		|| file[len - 3] != 'b' || file[len - 4] != '.')
		msg_exit("Error\nMap should be in '.ber' format.\n", 1);
}

static t_game	*initialize(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
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
	game->check_c = 0;
	game->check_e = 0;
	game->check_p = 0;
	game->left_c = 0;
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		msg_exit("Error\nNumber of arguments should be 2\n", 1);
	game = initialize();
	check_extension(argv[1]);
	save_map(argv[1], game);
	check_map(game);
	ft_init(game);
	free_img_tex(game);
	free_map(game);
	mlx_terminate(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
}
