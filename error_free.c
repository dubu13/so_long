/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:07:07 by dhasan            #+#    #+#             */
/*   Updated: 2024/01/30 19:38:36 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mapcopy(t_game *game)
{
	int	y;

	y = game->rows;

	while (y > 0)
		free(game->map_copy[--y]);
	free(game->map_copy);
	exit (EXIT_FAILURE);
}

void	ft_msg_exit(char *msg, int type)
{
	ft_printf("%s", msg);
	exit(type);
}
