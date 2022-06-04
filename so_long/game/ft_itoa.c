/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymirna <ymirna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:24:58 by ymirna            #+#    #+#             */
/*   Updated: 2022/05/31 21:31:20 by ymirna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static size_t	ft_rank(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_put(char	*str, unsigned int n, int ng, size_t	i)
{
	i--;
	str[i + ng + 1] = '\0';
	if (ng == 1)
		i++;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	if (ng == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			i;
	int				ng;
	unsigned int	ntrue;
	char			*str;

	ng = 0;
	i = 0;
	if (n < 0)
	{
		n = -n;
		ng++;
	}
	ntrue = (unsigned int)n;
	i = ft_rank(ntrue);
	str = (char *)malloc(sizeof(char) * (i + ng + 1));
	if (str == NULL)
		return (NULL);
	str = ft_put(str, ntrue, ng, i);
	return (str);
}
