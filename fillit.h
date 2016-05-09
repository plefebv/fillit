/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:51:58 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/15 17:20:14 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 2048

# include "libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_tetros
{
	char				**tetro;
	char				letter;
	int					x;
	int					y;
	struct s_tetros		*next;
}						t_tetros;

int						fillit(char *argv);
int						ft_valid_tetros(char **t, int nb_tetros);
char					**ft_read_argv(char *argv, int *nb_tetros);
int						ft_count_tetros(char *str);
t_tetros				*ft_create_list(char **tmp, int nb_tetros);
t_tetros				*ft_create_tetro(char **txt, int id);
void					ft_adj_tetro(t_tetros *begin);
void					ft_print_lst(t_tetros *lst, int nb_tetros);
char					**ft_gen_map(int size);
void					ft_free_tetros(char **tmp, int nb_tetros);
int						ft_can_place(t_tetros *t, char **map, int size);
char					**ft_place(t_tetros *tetro, char **map);
char					**ft_gen_map(int size);
void					ft_solve(t_tetros *tetro, int nb_tetros);
char					**ft_delete_tetro(t_tetros *t, char **map, int size);
int						ft_valid_shape2(char *tetro);
int						ft_valid_shape3(char *tetro);

#endif
