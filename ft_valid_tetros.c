/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 22:32:08 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/15 17:20:18 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_check_shape(char *t, int nb)
{
	if (nb == 0 && t[nb] == '#')
		if (!(t[nb + 1] == '#' || t[nb + 5] == '#'))
			return (0);
	if (nb > 0 && nb < 5 && t[nb] == '#')
		if (!(t[nb + 1] == '#' || t[nb - 1] == '#' || t[nb + 5] == '#'))
			return (0);
	if (nb > 4 && nb < 15 && t[nb] == '#')
		if (!(t[nb - 1] == '#' || t[nb + 1] == '#' || t[nb + 5] == '#'
				|| t[nb - 5] == '#'))
			return (0);
	if (nb > 14 && nb < 19 && t[nb] == '#')
		if (!(t[nb - 1] == '#' || t[nb + 1] == '#' || t[nb - 5] == '#'))
			return (0);
	if (nb == 19 && t[nb] == '#')
		if (!(t[nb - 1] == '#' || t[nb - 5] == '#'))
			return (0);
	return (1);
}

static int			ft_valid_shape(char *tetro)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (!(ft_check_shape(tetro, i)))
			return (0);
		i++;
	}
	return (1);
}

static int			ft_valid_line(char *tetro)
{
	int i;

	i = 0;
	while (tetro[i])
	{
		if (i % 5 == 4 && tetro[i] != '\n')
			return (0);
		if (i % 5 != 4 && tetro[i] != '#' && tetro[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int			ft_valid_char(char *tetro)
{
	int i;
	int hash;
	int dot;
	int bs;

	i = 0;
	hash = 0;
	dot = 0;
	bs = 0;
	while (tetro[i])
	{
		if (tetro[i] != '#' && tetro[i] != '.' && tetro[i] != '\n')
			return (0);
		if (tetro[i] == '#')
			hash++;
		if (tetro[i] == '.')
			dot++;
		if (tetro[i] == '\n')
			bs++;
		i++;
	}
	if (hash != 4 || dot != 12 || bs != 4)
		return (0);
	return (1);
}

int					ft_valid_tetros(char **t, int nb_tetros)
{
	int i;

	i = 0;
	while (i < nb_tetros)
	{
		if (!(ft_valid_char(t[i]))
				|| !(ft_valid_line(t[i]))
				|| !(ft_valid_shape(t[i]))
				|| !(ft_valid_shape2(t[i]))
				|| !(ft_valid_shape3(t[i])))
			return (0);
		i++;
	}
	return (1);
}
