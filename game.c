/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:16:40 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/05 22:13:18 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up_down(game, 'U');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_up_down(game, 'D');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left_right(game, 'L');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_left_right(game, 'R');
}

// void	handle_key(mlx_key_data_t keydata, void *param)
// {
// 	t_game		*game;
// 	const int	x = ((t_game *)param)->player->instances->x / 64;
// 	const int	y = ((t_game *)param)->player->instances->y / 64;

// 	game = param;
// 	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
// 		exit(EXIT_SUCCESS);
// 	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
// 		&& keydata.action == MLX_PRESS && game->map[y - 1][x] != WALL)
// 		game->player->instances->y -= 64;
// 	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
// 		&& keydata.action == MLX_PRESS && game->map[y + 1][x] != WALL)
// 		game->player->instances->y += 64;
// 	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
// 		&& keydata.action == MLX_PRESS && game->map[y][x - 1] != WALL)
// 		game->player->instances->x -= 64;
// 	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
// 		&& keydata.action == MLX_PRESS && game->map[y][x + 1] != WALL)
// 		game->player->instances->x += 64;
// }

void	move_in_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			ft_img_to_wnd(game, y, x);
			x++;
		}
		y++;
	}
}

void	ft_init(t_game *game)
{
	game->mlx_ptr = mlx_init(game->cols * IMG_PXL, game->rows * IMG_PXL,
			WND_NAME, true);
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		msg_exit("Error\nFailure in mlx_init!\n", 1);
	}
	ft_load_png(game);
	move_in_map(game);
	mlx_image_to_window(game->mlx_ptr, game->player, game->p_x * 64,
		game->p_y * 64);
	mlx_key_hook(game->mlx_ptr, handle_key, game);
	mlx_loop(game->mlx_ptr);
}
