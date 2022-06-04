/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:32:44 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 20:34:59 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	move_mimic_2(t_game	*game, int	*dx, int	*dy)
{
	if (*dy == -1)
	{
		*dy = 1;
		*dx = 0;
		return ;
	}
	else if (*dy == 1)
	{
		*dy = 0;
		*dx = -1;
		return ;
	}
	else
	{
		*dy = 0;
		*dx = 1;
		game->frame = 1;
		return ;
	}
}

void	move_mimic_1(t_game	*game, int	*dx, int	*dy)
{
	if (game->moves == 1)
		*dy = -1;
	if ((*dx == 1 && *dy == 0) && game->frame == 0)
	{
		*dx = 0;
		*dy = -1;
	}
}

void	move_mimic(t_game	*game)
{
	char		**map;
	int			x;
	int			y;
	static int	dy;
	static int	dx;

	map = game->map;
	x = game->mim->pos_x;
	y = game->mim->pos_y;
	move_mimic_1(game, &dx, &dy);
	while (1)
	{
		if (map[y + dy][x + dx] == '0')
		{
			map[y + dy][x + dx] = 'X';
			map[y][x] = '0';
			game->mim->pos_x = x + dx;
			game->mim->pos_y = y + dy;
			if (game->frame == 1 && map[y + dy][x + dx + 1] != '0')
				game->frame--;
			return ;
		}
		move_mimic_2(game, &dx, &dy);
		return ;
	}
}
