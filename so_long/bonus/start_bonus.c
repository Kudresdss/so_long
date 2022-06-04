/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:12:17 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 17:05:37 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	draw_tile_2(t_game	*game, char tile, int x, int y)
{
	if (tile == 'E' && game->coins == game->val->collect)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_exit_2, x * 100, y * 100);
	else if (tile == 'X' && !(game->moves % 2))
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_mimic, x * 100, y * 100);
	else if (tile == 'X' && (game->moves % 2))
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_mimic_2, x * 100, y * 100);
}

void	draw_tile(t_game	*game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_wall, x * 100, y * 100);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_floor, x * 100, y * 100);
	else if (tile == 'P' && !(game->moves % 2))
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_player_1, x * 100, y * 100);
	else if (tile == 'P' && (game->moves % 2))
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_player_2, x * 100, y * 100);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_collect, x * 100, y * 100);
	else if (tile == 'E' && game->coins != game->val->collect)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_exit, x * 100, y * 100);
	draw_tile_2(game, tile, x, y);
}

void	draw_map(t_game	*game, t_valid	*val, char	**map)
{
	val->y = 0;
	val->plr = 0;
	while (val->y < game->val->wid)
	{
		val->x = 0;
		while (val->x < game->val->len)
		{
			if (map[val->y][val->x] == 'P')
			{
				if (val->plr == 0)
				{
					game->plr->pos_x = val->x;
					game->plr->pos_y = val->y;
					val->plr++;
				}
				else
					map[val->y][val->x] = '0';
			}
			draw_tile(game, map[val->y][val->x], val->x, val->y);
			val->x++;
		}
		val->y++;
	}
}

void	get_images(t_game	*game)
{
	int	size[2];

	game->tile_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &size[0], &size[1]);
	game->tile_floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &size[0], &size[1]);
	game->tile_player_1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/player.xpm", &size[0], &size[1]);
	game->tile_player_2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_2.xpm", &size[0], &size[1]);
	game->tile_collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/mimic.xpm", &size[0], &size[1]);
	game->tile_exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &size[0], &size[1]);
	game->tile_exit_2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit_2.xpm", &size[0], &size[1]);
	game->tile_mimic = mlx_xpm_file_to_image(game->mlx,
			"./textures/mimic.xpm", &size[0], &size[1]);
	game->tile_mimic_2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/mimic_2.xpm", &size[0], &size[1]);
}

void	start_adv(t_valid	*val, char	**map_chr)
{
	t_char		player;
	t_mimic		mimic;
	t_game		game;

	game.plr = &player;
	game.mim = &mimic;
	game.val = val;
	game.map = map_chr;
	game.coins = 0;
	game.moves = 0;
	game.no_exit = 0;
	game.enemy = 0;
	init_enemy(&game, &mimic);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, val->len * 100,
			val->size * 100, "so_long");
	get_images(&game);
	draw_map(&game, val, map_chr);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx);
	clean_map(map_chr);
	exit(0);
}
