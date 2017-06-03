/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <eferrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:06:56 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/03 09:22:24 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	begin(t_tetri *t, int nb)
{
	short		*map;
	int			square;

	map = NULL;
	square = ft_sqrt(nb * 4);
	while (0 < backtracking(t, square, map, 0))
		++square;
}

int		cmp_map(short *map, t_coords c, t_tetri t)
{
	int i;

	i = t.y;
	while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x & (map[c.y + i])))
		--i;
	if ((((0xF000 >> (i * 4)) & t.data) >> c.x) & (map[c.y + i]))
		return (0);
	return (1);
}

/**
** operation sur le tetri :
** flag = PUT pour put le tetri sur la map
** flag = REMOVE pour remove le tetri de la map
**/
void	operand_tetri(short *map, t_coords c, t_tetri t, int flag)
{
	int i;

	i = t.y;
	if (flag == PUT)
	{
		while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x | (map[c.y + i])))
			--i;
	}
	else if (flag == REMOVE)
	{
		while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x ^ (map[c.y + i])))
			--i;
	}
}

/*void	affiche_ma_putain_de_lettre(short *map, int p, t_coords c, char *print)
{
	int i;

	i = 0;
	while (i <= p)
	{
		
		++i;
	}
}
*/
int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;
//	static char	*print = NULL;

	c.x = 0;
	c.y = 0;
	if (!map)
		map = (short[13]){0};
	while (c.y + t[p].y < square)
	{
		while (c.x + t[p].x < square && !cmp_map(map, c, t[p]))
			++c.x;
		if (c.x + t[p].x < square)
		{
			operand_tetri(map, c, t[p], PUT);

			if ((backtracking(t, square, map, p + 1)) && ++c.x)
				operand_tetri(map, c, t[p], REMOVE);
			else
			{
//				affiche_ma_putain_de_lettre(map, p, c, print);
				return (0);
			}
		}
		if (c.x + t[p].x >= square && !(c.x = 0))
			++c.y;
	}
	return (1);
}
