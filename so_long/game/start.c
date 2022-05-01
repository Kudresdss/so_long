/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:12:17 by ymirna            #+#    #+#             */
/*   Updated: 2022/04/29 21:49:10 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// несколько стартовых позиций обозначить

void	start_adv(t_valid	*val, char	**map_chr)
{
	//t_map	*map;
	// t_char	player;

	(void) map_chr;

	write(1, "Adventure time!\n", 16);
	printf("len = %d, size = %d\n", val->len, val->size);
	return ;
}