/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2025/09/01 17:21:11 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	char *ext;

	ext = ft_strrchr(file, '.');
	
	if (ext == NULL || ft_strncmp(ext, ".ber\0", 5) != 0)
		msg_exit("Error\nMap should be in '.ber' format.\n", 1);
}

int	main(void)
{
	t_game	*game;

	// if (argc != 2)
	// 	msg_exit("Error\nNumber of arguments should be 2.\n", 1);

	check_extension("valid3.ber");
	
	game = ft_calloc(1, sizeof(t_game));
	game->ended = 0;
	if (!game)
		msg_exit("Memory allocation failed.\n", 1);
	save_map("maps/valid3.ber", game);
	check_map(game);
	ft_init(game);
	free_img_tex(game);
	free_map(game->map, game->rows);
	mlx_terminate(game->mlx_ptr);
	free(game);
}
