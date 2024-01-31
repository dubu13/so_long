/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:07:07 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/31 17:53:21 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	y;

	y = game->rows;
	while (y > 0)
		free(game->map[--y]);
	free(game->map);
	exit (EXIT_FAILURE);
}

void	ft_msg_exit(char *msg, int type)
{
	ft_printf("%s", msg);
	exit(type);
}

void	ft_free_img_tex(t_game *game)
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
