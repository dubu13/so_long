/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/13 22:47:24 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	map_shape(game);
	check_elements(game);
	game->left_c = game->count_c;
	check_epc(game);
	check_wall(game);
	check_validpath(game);
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
	t_game			*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		exit(EXIT_FAILURE);
	game->moves = 0;
	game->rows = 0;
	game->cols = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
	game->left_c = 0;
	return (game);
}

void leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;
	atexit(&leaks);

	if (argc != 2)
		msg_exit("Error\nNumber of arguments should be 2\n", 1);
	check_extension(argv[1]);
	game = initialize();
	save_map(argv[1], game);
	check_map(game);
	ft_init(game);
	free_img_tex(game);
	// free_map(game);
	free_copy(game->map, game->rows);
	mlx_terminate(game->mlx_ptr);
	free(game);
}
