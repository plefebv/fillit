/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adj_tetro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 07:33:59 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/14 22:26:37 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_hmtc_y(char **str)
{
	int i;
	int car;
	int res;

	i = 0;
	car = 0;
	res = 0;
	while (i < 4)
	{
		while (str[i][car] != '#' && str[i][car] != '\0')
			car++;
		if (car == 4)
			res++;
		else
			return (res);
		car = 0;
		i++;
	}
	return (res);
}

static int		ft_hmtc_x(char **str)
{
	int i;
	int k;
	int res;

	i = 0;
	k = 0;
	res = 4;
	while (i < 4)
	{
		while (str[i][k] != '#' && str[i][k] != '\0')
			k++;
		if (k < res)
			res = k;
		k = 0;
		i++;
	}
	return (res);
}

static char		**ft_adj_y(char **s, int hmtc)
{
	int i;
	int k;
	int tmp;

	i = 0;
	k = 0;
	tmp = hmtc;
	while (i + hmtc < 4)
	{
		s[i] = s[i + hmtc];
		i++;
	}
	while (i < 4 && hmtc > 0)
	{
		s[i] = "....\0";
		i++;
	}
	return (s);
}

static char		**ft_adj_x(char **s, int hmtc)
{
	int i;
	int k;
	int tmp;

	i = 0;
	k = 0;
	tmp = 0;
	while (i < 4)
	{
		while (s[i][k + hmtc] != '\0')
		{
			s[i][k] = s[i][k + hmtc];
			k++;
		}
		tmp = hmtc;
		while (tmp > 0)
		{
			s[i][4 - tmp] = '.';
			tmp--;
		}
		k = 0;
		i++;
	}
	return (s);
}

void			ft_adj_tetro(t_tetros *begin)
{
	t_tetros	*cpy;

	cpy = begin;
	while (cpy)
	{
		cpy->tetro = ft_adj_x(cpy->tetro, ft_hmtc_x(cpy->tetro));
		cpy->tetro = ft_adj_y(cpy->tetro, ft_hmtc_y(cpy->tetro));
		cpy = cpy->next;
	}
}
