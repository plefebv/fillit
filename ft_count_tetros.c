/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:28:53 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/28 11:27:34 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int			ft_count_tetros(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 5] == '\n' && ((str[i + 6] == '\n') ||
					!(str[i + 6])))
		{
			res++;
		}
		i++;
	}
	return (res);
}

int			ft_valid_shape2(char *tetro)
{
	int		i;
	int		nb;
	int		hash;

	i = 0;
	nb = 0;
	hash = 0;
	while (i < 19)
	{
		if (tetro[i] == '#')
		{
			nb = 0;
			hash++;
		}
		if (hash == 4)
			return (1);
		if (nb > 4 && hash != 4 && hash != 0)
			return (0);
		nb++;
		i++;
	}
	return (1);
}

int			ft_valid_shape3(char *tetro)
{
	int	i;
	int	links;

	i = 0;
	links = 0;
	while (i < 19)
	{
		if (tetro[i] == '#')
		{
			if (tetro[i + 1] == '#')
				links++;
			if (i > 0 && tetro[i - 1] == '#')
				links++;
			if (i > 4 && tetro[i - 5] == '#')
				links++;
			if (i < 15 && tetro[i + 5] == '#')
				links++;
		}
		i++;
	}
	if (links < 6 || links > 8)
		return (0);
	return (1);
}
