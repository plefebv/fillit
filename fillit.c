/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:04:52 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/14 22:36:55 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_free_tetros(char **tmp, int nb_tetros)
{
	int i;

	i = 0;
	while (i < nb_tetros)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	ft_strdel(tmp);
}

int				fillit(char *argv)
{
	char		**tetros;
	int			nb_tetros;
	t_tetros	*begin;
	int			i;

	i = 0;
	nb_tetros = 0;
	tetros = ft_read_argv(argv, &nb_tetros);
	if (!tetros)
		return (0);
	if (!ft_valid_tetros(tetros, nb_tetros))
		return (0);
	begin = ft_create_list(tetros, nb_tetros);
	ft_free_tetros(tetros, nb_tetros);
	ft_solve(begin, nb_tetros);
	return (1);
}
