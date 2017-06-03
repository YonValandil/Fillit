/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:25:43 by jjourne           #+#    #+#             */
/*   Updated: 2017/06/03 05:29:13 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUFF_SIZE 546
#define PUT 1
#define REMOVE 0

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct	s_coords
{
    int			x;
    int			y;
}				t_coords;

typedef struct	s_tetri
{
	short		data;
    int			x;
	int			y;
}				t_tetri;

int     parse_file(char *buf, t_tetri*);
int     check_tetri(t_tetri *t);
int		set_tetri(t_tetri*);
void	begin(t_tetri*, int rd);
int		backtracking(t_tetri*, int, short*, int);
void	operand_tetri(short *map, t_coords c, t_tetri t, int flag);
void	affiche_ma_putain_de_lettre(short *map, int p, t_coords c);

#endif
