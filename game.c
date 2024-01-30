/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:16:40 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 20:20:44 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit (0);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		ft_move_up_down(game, 'U');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		ft_move_up_down(game, 'D');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		ft_move_left_right(game, 'L');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		ft_move_left_right(game, 'R');
}

void	ft_move_in_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			ft_pass_to_wnd(game, y, x);
			x++;
		}
		y++;
	}
}

void	ft_init(t_game *game)
{
	game->mlx_ptr = mlx_init(game->rows * IMG_PXL, game->cols * IMG_PXL,
			WND_NAME, true);
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		ft_msg_exit("Error\nFailure in mlx_init!\n", 1);
	}
	ft_pass_texture(game);
	ft_move_in_map(game);
	mlx_key_hook(game->mlx_ptr, ft_handle_key, game);
}
