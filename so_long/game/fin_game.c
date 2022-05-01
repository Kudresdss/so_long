/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:41:01 by ymirna            #+#    #+#             */
/*   Updated: 2022/04/19 20:47:20 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	clean_map(char	**map, int	ext)
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
	write(2, "Error\n", 6);
	exit(ext);
}
