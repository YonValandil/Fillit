/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:25:43 by jjourne           #+#    #+#             */
/*   Updated: 2017/06/03 09:24:49 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUFF_SIZE 546
#define PUT 1
#define REMOVE 0
# define T1 0xF000
# define T2 0x8888
# define T3 0xE400
# define T4 0x4E00
# define T5 0x8C80
# define T6 0x4C40
# define T7 0x8E00
# define T8 0xE800
# define T9 0x2E00
# define T10 0xE200
# define T11 0xC880
# define T12 0xC440
# define T13 0x88C0
# define T14 0x44C0
# define T15 0xC600
# define T16 0x6C00
# define T17 0x8C40
# define T18 0x4C80
# define T19 0xCC00

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct		s_coords
{
    int				x;
    int				y;
}					t_coords;

typedef struct		s_tetri
{
	unsigned short	data;
    int				x;
	int				y;
}					t_tetri;

int  				parse_file(char *buf, t_tetri*);
int					set_tetri(t_tetri*, int);
void				begin(t_tetri*, int);
int					backtracking(t_tetri*, int, short*, int);
void				operand_tetri(short *map, t_coords c, t_tetri t, int flag);
void				affiche_ma_putain_de_lettre(short *map, int p, t_coords c);

#endif
