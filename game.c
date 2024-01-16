/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:16:40 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/16 16:15:26 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_key(int key_input, t_game *game)
{
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		ft_end_game(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx_ptr, MLX_KEY_UP))
		ft_move(game->p_x, game->p_y - 1);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx_ptr, MLX_KEY_DOWN))
		ft_move(game->p_x, game->p_y + 1);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx_ptr, MLX_KEY_LEFT))
		ft_move(game->p_x - 1, game->p_y);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx_ptr, MLX_KEY_RIGHT))
		ft_move(game->p_x + 1, game->p_y);
	return (0);
}

void	ft_init(t_game *game)
{
	game->mlx_ptr = mlx_init(game->height * IMG_PXL, \
		game->width * IMG_PXL, WND_NAME, true);
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_printf("Failer in mlx_init!");
	}
	game->window_ptr = mlx_new_window(game->mlx_ptr, \
		game->height * IMG_PXL, game->width * IMG_PXL, WND_NAME);
	if (game->window_ptr == NULL)
	{
		free(game->window_ptr);
		ft_printf("Problem while creating the window!");
	}
	ft_pass_texture(t_game *game, t_image *image);
}
