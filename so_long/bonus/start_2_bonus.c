/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:04:17 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 19:59:22 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	key_hook(int key, t_game	*game)
{
	int	x;
	int	y;

	x = game->plr->pos_x;
	y = game->plr->pos_y;
	if (game->enemy == 1 && (game->moves % 2 == 1))
		move_mimic(game);
	if (key == 13)
		move_up(game, x, y);
	else if (key == 1)
		move_down(game, x, y);
	else if (key == 0)
		move_left(game, x, y);
	else if (key == 2)
		move_right(game, x, y);
	else if (key == 53)
		close_game(game);
	return (0);
}

void	add_evil(t_valid	*val, char	**map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				val->collect--;
				map[y][x] = 'X';
				val->mim_x = x;
				val->mim_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_enemy(t_game	*game, t_mimic	*mimic)
{
	mimic->pos_x = game->val->mim_x;
	mimic->pos_y = game->val->mim_y;
	game->enemy = 1;
	game->frame = 0;
}
