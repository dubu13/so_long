/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/05 22:52:32 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	allocate_collectibles(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	game->collectibles = ft_calloc(sizeof(t_collectibles), game->count_c);
// 	game->left_c = game->count_c;
// }

void	check_map(t_game *game)
{
	map_shape(game);
	check_elements(game);
	game->left_c = game->count_c;
	// allocate_collectibles(game);
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
	t_game			*game;
	t_collectibles	*collectibles;

	game = ft_calloc(sizeof(t_game), 1);
	collectibles = ft_calloc(sizeof(t_collectibles), 1);
	game->player = 0;
	game->collectible = 0;
	game->exit = 0;
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

// void	print_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->rows)
// 	{
// 		ft_putstr_fd(game->map[i], 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		msg_exit("Error\nNumber of arguments should be 2\n", 1);
	game = initialize();
	check_extension(argv[1]);
	save_map(argv[1], game);
	// print_map(game);
	check_map(game);
	ft_init(game);
	free_img_tex(game);
	free_map(game);
	mlx_terminate(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
}
