/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:46:21 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/14 22:28:46 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
}

static int		ft_try(t_tetros *tetro, char **map, int size)
{
	if (tetro != NULL)
	{
		while (tetro->x * tetro->y < size * size)
		{
			if ((ft_can_place(tetro, map, size)) == 1)
			{
				map = ft_place(tetro, map);
				if ((ft_try(tetro->next, map, size)) == 1)
					return (1);
				map = ft_delete_tetro(tetro, map, size);
			}
			if (tetro->x < size)
				tetro->x++;
			else
			{
				tetro->y++;
				tetro->x = 0;
			}
		}
		tetro->y = 0;
		tetro->x = 0;
		return (0);
	}
	return (1);
}

void			ft_solve(t_tetros *tetro, int nb_tetros)
{
	char	**map;
	int		size;

	size = nb_tetros / 2;
	map = ft_gen_map(size);
	ft_adj_tetro(tetro);
	while (ft_try(tetro, map, size) == 0)
	{
		tetro->x = 0;
		tetro->y = 0;
		size++;
		ft_free_tetros(map, size);
		map = ft_gen_map(size);
	}
	ft_print_map(map);
}
