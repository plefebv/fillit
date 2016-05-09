/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:32:43 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/14 22:36:17 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_gen_map(int size)
{
	char	**map;
	int		i;
	int		k;

	i = 0;
	k = 0;
	map = ft_memalloc(sizeof(char *) * size + sizeof(char *) * 1);
	while (i < size + 1)
	{
		map[i] = ft_memalloc(sizeof(char) * (size + 1));
		i++;
	}
	i = 0;
	while (i < size)
	{
		while (k < size)
		{
			map[i][k] = '.';
			k++;
		}
		k = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char		**ft_place(t_tetros *tetros, char **map)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		while (k < 4)
		{
			if (tetros->tetro[i][k] == '#')
				map[tetros->y + i][tetros->x + k] = tetros->letter;
			k++;
		}
		k = 0;
		i++;
	}
	return (map);
}

int			ft_can_place(t_tetros *t, char **map, int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		while (k < 4)
		{
			if (t->tetro[i][k] == '#' && ((t->y + i) >= size
						|| (t->x + k >= size)))
				return (0);
			if (t->tetro[i][k] == '#' &&
					ft_isalpha(map[t->y + i][t->x + k]) == 1)
				return (0);
			k++;
		}
		k = 0;
		i++;
	}
	return (1);
}

char		**ft_delete_tetro(t_tetros *t, char **map, int size)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		while (k < size)
		{
			if (map[i][k] == t->letter)
				map[i][k] = '.';
			k++;
		}
		k = 0;
		i++;
	}
	return (map);
}
