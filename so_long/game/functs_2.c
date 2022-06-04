/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:46:13 by ymirna            #+#    #+#             */
/*   Updated: 2022/05/31 21:54:19 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	valid_cycle(t_valid	*val, char	*buf)
{
	if (buf[0] == '\n')
		val->size++;
	else if (buf[0] == 'P')
		val->player++;
	else if (buf[0] == 'E')
		val->exit++;
	else if (buf[0] == 'C')
		val->collect++;
	else if (buf[0] != 'P' && buf[0] != '0' && buf[0] != '1'
		&& buf[0] != 'C' && buf[0] != 'E' && buf[0] != 'X'
		&& buf[0] != '\n')
		return (1);
	return (0);
}

int	valid_read_2(t_valid	*val, char	*buf, int fd)
{
	while (val->chr)
	{
		val->chr = read(fd, buf, 1);
		if (val->chr)
		{
			if (valid_cycle(val, buf))
				return (0);
		}
	}
	if (buf[0] == '\n')
		val->size--;
	if (val->player == 0 || val->exit == 0 || val->collect == 0)
		return (0);
	return (val->size);
}

int	valid_read_1(t_valid	*val, int fd)
{
	char	buf[1];

	val->size = 1;
	val->player = 0;
	val->exit = 0;
	val->collect = 0;
	val->chr = 1;
	return (valid_read_2(val, buf, fd));
}

void	move_count(t_game	*game)
{
	char	*moves;

	write(1, "step ", 5);
	moves = ft_itoa(game->moves);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
}
