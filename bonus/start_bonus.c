/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:16:40 by dhasan            #+#    #+#             */
/*   Updated: 2024/02/17 15:20:46 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		&& keydata.action == MLX_PRESS)
		exit (EXIT_SUCCESS);
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

void	ft_img_to_wnd(t_game *game, int y, int x)
{
	char	pos;

	pos = game->map[y][x];
	if (pos == FLOOR || pos == WALL || pos == PLAYER
		|| pos == COLLECTIBLE || pos == EXIT)
		mlx_image_to_window(game->mlx_ptr, game->floor,
			x * IMG_PXL, y * IMG_PXL);
	if (pos == WALL)
		mlx_image_to_window(game->mlx_ptr, game->wall,
			x * IMG_PXL, y * IMG_PXL);
	else if (pos == COLLECTIBLE)
		mlx_image_to_window(game->mlx_ptr, game->collectible,
			x * IMG_PXL, y * IMG_PXL);
	else if (pos == EXIT)
		mlx_image_to_window(game->mlx_ptr, game->exit,
			x * IMG_PXL, y * IMG_PXL);
}

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
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx_ptr = mlx_init(game->cols * IMG_PXL, game->rows * IMG_PXL,
			WND_NAME, true);
	if (!game->mlx_ptr)
	{
		free(game->mlx_ptr);
		msg_exit("Error\nFailure in mlx_init!\n", 1);
	}
	ft_load_png(game);
	move_in_map(game);
	mlx_image_to_window(game->mlx_ptr, game->player, game->p_x * IMG_PXL,
		game->p_y * IMG_PXL);
	mlx_image_to_window(game->mlx_ptr, game->player_b, game->p_x * IMG_PXL,
		game->p_y * IMG_PXL);
	game->player_b->instances[0].enabled = false;
	mlx_image_to_window(game->mlx_ptr, game->player_l, game->p_x * IMG_PXL,
		game->p_y * IMG_PXL);
	game->player_l->instances[0].enabled = false;
	mlx_image_to_window(game->mlx_ptr, game->player_r, game->p_x * IMG_PXL,
		game->p_y * IMG_PXL);
	game->player_r->instances[0].enabled = false;
	mlx_key_hook(game->mlx_ptr, handle_key, game);
	mlx_loop(game->mlx_ptr);
}
