/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:59:48 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 16:14:19 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_tile(t_game	*game, int dy, int dx)
{
	int	x;
	int	y;

	x = game->plr->pos_x;
	y = game->plr->pos_y;
	if (game->map[y + dy][x + dx] == 'C')
		game->coins++;
	else if (game->map[y + dy][x + dx] == 'X')
		game_over(game);
	else if (game->map[y + dy][x + dx] == 'E')
	{
		if (game->coins == game->val->collect)
			return (2);
		else
			return (0);
	}
	return (1);
}

void	move_up(t_game	*game, int x, int y)
{
	int	check;

	check = check_tile(game, -1, 0);
	if (game->map[y - 1][x] != '1' && check)
	{
		game->plr->pos_y--;
		y = game->plr->pos_y;
		game->moves++;
		game->strmv = move_count(game);
		game->map[y][x] = 'P';
		game->map[y + 1][x] = '0';
		game->plr->pos_y--;
		draw_map(game, game->val, game->map);
		mlx_string_put(game->mlx, game->win, 24, 24, -1, game->strmv);
		free(game->strmv);
		if (check == 2)
			fin_game(game);
		return ;
	}
}

void	move_down(t_game	*game, int x, int y)
{
	int	check;

	check = check_tile(game, 1, 0);
	if (game->map[y + 1][x] != '1' && check)
	{
		game->plr->pos_y++;
		y = game->plr->pos_y;
		game->moves++;
		game->strmv = move_count(game);
		game->map[y - 1][x] = '0';
		game->map[y][x] = 'P';
		game->plr->pos_y++;
		draw_map(game, game->val, game->map);
		mlx_string_put(game->mlx, game->win, 24, 24, -1, game->strmv);
		free(game->strmv);
		if (check == 2)
			fin_game(game);
		return ;
	}
}

void	move_left(t_game	*game, int x, int y)
{
	int	check;

	check = check_tile(game, 0, -1);
	if (game->map[y][x - 1] != '1' && check)
	{
		game->plr->pos_x--;
		x = game->plr->pos_x;
		game->moves++;
		game->strmv = move_count(game);
		game->map[y][x + 1] = '0';
		game->map[y][x] = 'P';
		game->plr->pos_x--;
		draw_map(game, game->val, game->map);
		mlx_string_put(game->mlx, game->win, 24, 24, -1, game->strmv);
		free(game->strmv);
		if (check == 2)
			fin_game(game);
		return ;
	}
}

void	move_right(t_game	*game, int x, int y)
{
	int	check;

	check = check_tile(game, 0, 1);
	if (game->map[y][x + 1] != '1' && check)
	{
		game->plr->pos_x++;
		x = game->plr->pos_x;
		game->moves++;
		game->strmv = move_count(game);
		game->map[y][x - 1] = '0';
		game->map[y][x] = 'P';
		game->plr->pos_x++;
		draw_map(game, game->val, game->map);
		mlx_string_put(game->mlx, game->win, 24, 24, -1, game->strmv);
		free(game->strmv);
		if (check == 2)
			fin_game(game);
		return ;
	}
}
