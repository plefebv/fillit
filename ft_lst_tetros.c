/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tetros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 00:14:05 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/14 22:25:08 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_print_lst(t_tetros *lst, int nb_tetros)
{
	int			i;
	int			k;
	t_tetros	*cpy;

	i = 0;
	k = 0;
	if (lst)
	{
		cpy = lst;
		while (i < nb_tetros)
		{
			ft_putstr("Tetros ");
			ft_putchar(cpy->letter);
			ft_putchar('\n');
			while (k < 4)
			{
				ft_putendl(cpy->tetro[k]);
				k++;
			}
			k = 0;
			cpy = cpy->next;
			i++;
		}
	}
}

t_tetros		*ft_create_tetro(char **txt, int id)
{
	t_tetros	*new;

	new = NULL;
	new = (t_tetros *)malloc(sizeof(t_tetros));
	if (!new)
		return (NULL);
	new->tetro = txt;
	new->letter = 'A' + id;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

t_tetros		*ft_create_list(char **tmp, int nb_tetros)
{
	int			i;
	t_tetros	*begin;
	t_tetros	*lst;

	i = 1;
	begin = NULL;
	lst = NULL;
	begin = ft_create_tetro(ft_strsplit(tmp[0], '\n'), 0);
	lst = begin;
	while (i < nb_tetros)
	{
		lst->next = ft_create_tetro(ft_strsplit(tmp[i], '\n'), i);
		lst = lst->next;
		i++;
	}
	lst->next = NULL;
	return (begin);
}
