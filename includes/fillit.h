/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:25:43 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/08 04:11:38 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUF_SIZE 546

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#include <stdio.h> //a supr !!!!

typedef struct      s_coords
{
    int     x;
    int     y;
}                   t_coords;

typedef struct      s_map
{
    int     x;
    int     y;
    char    *map;
}                   t_map;

typedef struct      s_piece
{
    t_coords     min;
    t_coords     max;
}                   t_piece;

typedef struct      s_tetri
{
    int         nb;
    char        **tetriminos;
    char        **tetris_min;
    t_piece p[26];
}                   t_tetri;

char	*read_file(char *file);
int     parse_file(char *file_content, char ***tetriminos);
int     check_tetris(t_tetri *t);
int		check_tetri(t_tetri *t, int k, int j, int four);
int     move_tetri(t_tetri *t, int j);
void	trim_piece(t_tetri *t, int piece_nb);
void	recup_tetris_min(t_tetri *t);
//char    *filling_map(t_tetri *t, t_map *m);
char    *resize_map(t_tetri *t, t_map *m);
int     cmp_map(t_tetri *t, t_map *m);
void    resolv(t_tetri *t, t_map *m);

#endif
