/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/12/25 20:53:22 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set(t_game *game)
{
	game->player = 0;
	game->collectible = 0;
	game->exit = 0;
	game->movements = 0;
}

void	ft_pass_texture(t_image *image, t_game *game)
{
	mlx_image_t	*png;

	png = mlx_load_png(WALL_PNG);
	image->wall = mlx_texture_to_image(game->mlx_ptr, png);
	png = mlx_load_png(FLOOR_PNG);
	image->floor = mlx_texture_to_image(game->mlx_ptr, png);
	png = mlx_load_png(PLAYER_PNG);
	image->player = mlx_texture_to_image(game->mlx_ptr, png);
	png = mlx_load_png(COLLECTIBLE_PNG);
	image->collectible = mlx_texture_to_image(game->mlx_ptr, png);
	png = mlx_load_png(EXIT_PNG);
	image->exit = mlx_texture_to_image(game->mlx_ptr, png);
	if (png == NULL)
		ft_printf("Png can not load.");
}

void	ft_update(t_game *game, int x, int y)
{
	if (game->map[x][y] == PLAYER)
	{
		game->player++;
		game->p_x = x;
		game->p_y = y;
	}
	if (game->map[x][y] == COLLECTIBLE)
		game->collectible++;
	if (game->map[x][y] == EXIT)
		game->exit++;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	t_game	*image;

	if (argc != 2)
		ft_printf("Error\nNumber of arguments should be 2\n");
	ft_check_file(argv[1]);
	ft_check_map(game);
	ft_check_map2(game);
	ft_check_wall(game);
	ft_mlx_init(game);
	ft_pass_texture(image, game);
	ft_set(game);
}
