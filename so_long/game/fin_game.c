/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:41:01 by ymirna            #+#    #+#             */
/*   Updated: 2022/05/31 21:48:49 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"	

int	exit_hook(t_game	*game)
{
	clean_map(game->map);
	exit(0);
}

void	close_game(t_game	*game)
{
	clean_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	fin_game(t_game	*game)
{
	write(1, "You win!\n", 9);
	clean_map(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	clean_map(char	**map)
{
	int	i;

	i = 0;
	if (map[0])
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
	}
	free(map);
}
