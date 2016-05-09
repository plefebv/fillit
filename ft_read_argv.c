/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:13:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/28 11:27:39 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_check_argv(char *tmp)
{
	int i;
	int line;

	i = 0;
	line = 0;
	if (ft_strlen(tmp) % 21 == 20 && ft_strlen(tmp) < 546)
	{
		while (tmp[i])
		{
			if (tmp[i] != '\n')
				line++;
			if (line == 4)
			{
				if (tmp[i + 1] != '\n' || !(tmp[i + 1]))
					return (0);
				if (tmp[i + 1] == '\n')
					line++;
				line = 0;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

static char			**ft_cut_tetros(char *in, char **out)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < ft_count_tetros(in))
	{
		out[k] = (char *)malloc(sizeof(char) * 21);
		if (out[k] == NULL)
			return (NULL);
		while (j < 20)
		{
			out[k][j] = in[i];
			j++;
			i++;
		}
		out[k][20] = '\0';
		j = 0;
		k++;
		i++;
	}
	out[k] = NULL;
	return (out);
}

char				**ft_read_argv(char *argv, int *nb_tetros)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**res;

	ret = 1;
	res = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	if (!(ft_check_argv(buf)))
		return (NULL);
	nb_tetros[0] = ft_count_tetros(buf);
	res = (char**)malloc(sizeof(char *) * (nb_tetros[0] + 1));
	if (!(res))
		return (NULL);
	res = ft_cut_tetros(buf, res);
	return (res);
}
