/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 04:40:39 by jjourne           #+#    #+#             */
/*   Updated: 2017/04/16 23:22:43 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parse_min_y(char *tetri)
{
	t_coords	i;

	i.y = -1;
	while (++i.y < 4)
	{
		i.x = -1;
		while (++i.x < 4)
			if (tetri[i.y * 4 + i.x])
				return (i.y);
	}
	return (-1);
}

int		parse_min_x(char *tetri)
{
	t_coords	i;

	i.x = -1;
	while (++i.x < 4)
	{
		i.y = -1;
		while (++i.y < 4)
			if (tetri[i.y * 4 + i.x])
				return (i.x);
	}
	return (-1);
}

int		parse_max_y(char *tetri)
{
	t_coords	i;

	i.y = 4;
	while (--i.y > -1)
	{
		i.x = -1;
		while (++i.x < 4)
			if (tetri[i.y * 4 + i.x])
				return (i.y);
	}
	return (-1);
}

int		parse_max_x(char *tetri)
{

	t_coords	i;

	i.x = 4;
	while (--i.x > -1)
	{
		i.y = -1;
		while (++i.y < 4)
			if (tetri[i.y * 4 + i.x])
				return (i.x);
	}
	return (-1);
}

void	trim_piece(t_tetri *t, int piece_nb)
{
	t->p[piece_nb].min.y = parse_min_y(t->tetriminos[piece_nb]);
	t->p[piece_nb].min.x = parse_min_x(t->tetriminos[piece_nb]);
	t->p[piece_nb].max.y = parse_max_y(t->tetriminos[piece_nb]);
	t->p[piece_nb].max.x = parse_max_x(t->tetriminos[piece_nb]);
}
