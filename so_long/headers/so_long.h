/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:28:58 by ymirna            #+#    #+#             */
/*   Updated: 2022/04/29 21:51:29 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct	s_valid
{
	int	fd_map;
	int	len;
	int	wid;
	int	chr;
	int	size;
	int	ret;
	int	player;
	int	exit;
	int	collect;
	int	enemy;
}				t_valid;

typedef struct	s_char
{
	int		x;
	int		y;		
	void	*current_img;
}				t_char;

typedef	struct s_game
{
	t_char	player;
	int		coins;
	int		moves;
}				t_game;

void	clean_map(char	**map, int	ext);
int		map_check_1(t_valid	*val, char	**map);
char	*get_next_line(int	fd);
void	start_adv(t_valid	*val, char	**map);
int		ft_strlen(const char	*s);
int		ft_strncmp(const char	*s1, const char	*s2, int n);
char	*cut_n(char	*line);

#endif