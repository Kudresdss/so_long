/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:44:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/01 20:14:02 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	ber_check(char	*file)
{
	return (ft_strncmp(file + (ft_strlen(file) - 4), ".ber", 4));
}

int	get_fd(char	**av, int fd, int x)
{
	if (x == 2)
		close(fd);
	fd = open(av[1], O_RDONLY);
	return (fd);
}

int	main_next(char	**av)
{
	t_valid	val;
	char	**map;
	int		size;

	val.fd_map = get_fd(av, 0, 1);
	size = valid_read_1(&val, val.fd_map);
	if (!size)
		return (2);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (5);
	map[size] = NULL;
	val.fd_map = get_fd(av, val.fd_map, 2);
	val.size = 0;
	while (val.size < size)
	{
		map[val.size] = cut_n(get_next_line(val.fd_map));
		val.size++;
	}
	val.ret = map_check_1(&val, map);
	if (!val.ret)
		start_adv(&val, map);
	clean_map(map);
	return (val.ret);
}

int	main(int ac, char	**av)
{
	int	ret;

	if (ac != 2 || ber_check(av[1]))
	{
		write(2, "Error\nInvalid arguments\n", 24);
		exit(1);
	}
	ret = main_next(av);
	if (ret)
	{
		write(2, "Error\n", 6);
		if (ret == 2)
			write(2, "Invalid map: wrong characters\n", 30);
		else if (ret == 3)
			write(2, "Invalid map: not rectangular\n", 29);
		else if (ret == 4)
			write(2, "Invalid map: wrong borders\n", 27);
		else if (ret == 5)
			write(2, "Malloc problem\n", 15);
	}
	return (ret);
}
