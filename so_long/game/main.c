/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:44:56 by ymirna            #+#    #+#             */
/*   Updated: 2022/04/19 21:24:00 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//Стартовых позиций может быть несколько
//Вынести условия со врагами из основной части

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
	else if (buf[0] == 'X')
		val->enemy++;
	else if(buf[0] != 'P' && buf[0] != '0' && buf[0] != '1' &&
			buf[0] != 'C' && buf[0] != 'E' && buf[0] != 'X' &&
			buf[0] != '\n')
		return (1);
	return (0);
}

int	valid_read_2(t_valid	*val, char	*buf, int fd)
{
	while(val->chr)
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
	val->enemy = 0;
	val->chr = 1;

	return(valid_read_2(val, buf, fd));
}

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

int	main_next(int ac, char	**av)
{
	t_valid	val;
	char	**map;
	int		size;

	if (ac != 2 || ber_check(av[1]))
	{
		printf("Invalid args\n");
		return (1);
	}
	val.fd_map = get_fd(av, 0, 1);
	size = valid_read_1(&val, val.fd_map);
	if (!size)
		return (1);
	printf("size = %d\n", size);
	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (1);
	map[size] = NULL;
	val.fd_map = get_fd(av, val.fd_map, 2);
	val.size = 0;
	while(val.size < size)
	{
		map[val.size] = cut_n(get_next_line(val.fd_map));
		val.size++;
		// if (!map[val.size - 1] && val.size != size)
		// 	clean_map(map);
	}
	val.ret = map_check_1(&val, map);
	printf("%d\n", val.ret);
	if (!val.ret)
		start_adv(&val, map);
	return (val.ret);
}

int	main(int ac, char	**av)
{
	int	ret;
	
	ret = main_next(ac, av);
	if (ret)
		write(2, "Error\n", 6);
	return (ret);
}
