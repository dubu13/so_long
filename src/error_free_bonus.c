/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:07:07 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/15 20:03:41 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map, int rows)
{
	int	y;

	y = rows;
	while (y > 0)
		free(map[--y]);
	free(map);
}

void	msg_exit(char *msg, int type)
{
	ft_printf("%s", msg);
	exit(type);
}

void	free_img_tex(t_game *game)
{
	mlx_delete_image(game->mlx_ptr, game->wall);
	mlx_delete_image(game->mlx_ptr, game->floor);
	mlx_delete_image(game->mlx_ptr, game->player);
	mlx_delete_image(game->mlx_ptr, game->collectible);
	mlx_delete_image(game->mlx_ptr, game->exit);
	mlx_delete_texture(game->wall_tex);
	mlx_delete_texture(game->floor_tex);
	mlx_delete_texture(game->player_tex);
	mlx_delete_texture(game->collectible_tex);
	mlx_delete_texture(game->exit_tex);
}
