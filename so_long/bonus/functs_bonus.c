/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:40:59 by ymirna            #+#    #+#             */
/*   Updated: 2022/06/02 17:06:15 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	ft_strlen(const char	*s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_strncmp(const char	*s1, const char	*s2, int n)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n && (ss1[i] || ss2[i]))
	{
		if (ss1[i] == s2[i])
			i++;
		else
			return (ss1[i] - ss2[i]);
	}
	return (0);
}

char	*cut_n(char	*line)
{
	int		i;
	int		len;
	char	*line_2;

	i = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line_2 = (char *)malloc(sizeof(char) * (len + 1));
		while (i < len - 1)
		{
			line_2[i] = line[i];
			i++;
		}
		free(line);
		return (line_2);
	}
	return (line);
}

int	map_check_2(t_valid	*val, char	**map)
{
	int	len;
	int	wid;

	wid = 0;
	while (map[wid] && wid <= val->size - 1)
	{
		len = 0;
		while (map[wid][len])
		{
			if (map[wid][len] != '1')
				return (4);
			len++;
		}
		wid += val->size - 1;
	}
	len--;
	wid = 0;
	while (map[wid] && wid <= val->size - 1)
	{
		if (map[wid][0] != '1' || map[wid][len] != '1')
			return (4);
		wid++;
	}
	return (0);
}

int	map_check_1(t_valid	*val, char	**map)
{
	int	len_x;

	val->wid = 0;
	len_x = ft_strlen(map[val->size - 1]);
	while (val->wid < val->size)
	{
		val->len = ft_strlen(map[val->wid]);
		if (len_x == val->len)
			val->wid++;
		else
			return (3);
	}
	add_evil(val, map);
	return (map_check_2(val, map));
}
