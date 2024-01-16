/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:58:41 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/16 21:47:42 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pass_texture(t_image *image, t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(WALL_PNG);
	image->wall = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(FLOOR_PNG);
	image->floor = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(PLAYER_PNG);
	image->player = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(COLLECTIBLE_PNG);
	image->collectible = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(EXIT_PNG);
	image->exit = mlx_texture_to_image(game->mlx_ptr, texture);
	mlx_delete_texture(texture);
	if (texture == NULL)
		ft_printf("Png can not load.");
}
