/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:28:58 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 19:53:57 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"

typedef struct s_valid
{
	int	x;
	int	y;
	int	mim_x;
	int	mim_y;
	int	plr;
	int	fd_map;
	int	len;
	int	wid;
	int	chr;
	int	size;
	int	ret;
	int	player;
	int	exit;
	int	collect;
}				t_valid;

typedef struct s_char
{
	int		pos_x;
	int		pos_y;
}				t_char;

typedef struct s_mimic
{
	int		pos_x_prev;
	int		pos_y_prev;
	int		pos_x;
	int		pos_y;
}				t_mimic;

typedef struct s_game
{
	t_char	*plr;
	t_valid	*val;
	t_mimic	*mim;
	void	*mlx;
	void	*win;
	char	**map;
	char	*strmv;
	int		frame;
	int		coins;
	int		enemy;
	int		moves;
	int		fin;
	int		no_exit;
	void	*tile_wall;
	void	*tile_floor;
	void	*tile_player_1;
	void	*tile_player_2;
	void	*tile_collect;
	void	*tile_exit;
	void	*tile_exit_2;
	void	*tile_mimic;
	void	*tile_mimic_2;
}				t_game;

void	clean_map(char	**map);
int		map_check_1(t_valid	*val, char	**map);
int		valid_cycle(t_valid	*val, char	*buf);
int		valid_read_2(t_valid	*val, char	*buf, int fd);
int		valid_read_1(t_valid	*val, int fd);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
void	start_adv(t_valid	*val, char	**map);
int		ft_strlen(const char	*s);
int		ft_strncmp(const char	*s1, const char	*s2, int n);
char	*cut_n(char	*line);
void	draw_map(t_game	*game, t_valid	*val, char	**map);
void	move_up(t_game	*game, int x, int y);
void	move_down(t_game	*game, int x, int y);
void	move_left(t_game	*game, int x, int y);
void	move_right(t_game	*game, int x, int y);
char	*move_count(t_game	*game);
void	fin_game(t_game	*game);
void	close_game(t_game	*game);
int		exit_hook(t_game	*game);
void	game_over(t_game	*game);
int		key_hook(int key, t_game	*game);
void	add_evil(t_valid	*val, char	**map);
void	init_enemy(t_game	*game, t_mimic	*mimic);
void	move_mimic(t_game	*game);

#endif