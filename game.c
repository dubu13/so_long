/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:16:40 by dhasan            #+#    #+#             */
/*   Updated: 2023/12/25 20:50:16 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_key(int key_input, t_game *game)
{
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE) == 1)
		ft_end_game(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W) == 1)
		ft_move(game->p_x, game->p_y - 1);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_S) == 1)
		ft_move(game->p_x, game->p_y + 1);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_A) == 1)
		ft_move(game->p_x - 1, game->p_y);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_D) == 1)
		ft_move(game->p_x + 1, game->p_y);
	return (0);
}

void	(t_game *game)
{
	game->mlx_ptr = mlx_init();

	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_printf("Failer in mlx_init!");
	}
	game->window_ptr = mlx_new_window(game->mlx_ptr, \
								game->lenght * 32, game->width * 32, "so_long");
	if (game->window_ptr == NULL)
	{
		free(game->window_ptr);
		ft_printf("Problem while creating the window!");
	}
}