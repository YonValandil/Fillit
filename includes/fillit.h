/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:25:43 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/19 11:33:48 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#define BUFF_SIZE 546

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

void	begin(t_tetris*);
int		backtracking(t_tetris*, int, short*, int);
char	*read_file(char *file);
int		set_tetri(t_tetri*);
int     parse_file(char *file_content, t_tetri*);
int     check_tetri(t_tetri *t);

#endif
