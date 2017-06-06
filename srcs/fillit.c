/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <eferrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:06:56 by eferrand          #+#    #+#             */
/*   Updated: 2017/06/06 08:37:59 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	operand_tetri(short *map, t_coords c, t_tetri t, int flag)
{
	int i;

	i = t.y;
	if (flag == PUT)
		while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x | (map[c.y + i])))
			--i;
	else if (flag == REMOVE)
		while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x ^ (map[c.y + i])))
			--i;
}

void	ft_display(square, t_tetri t, p, t_coords c)
{
	int i;
	int size;
	static char *display = NULL;

	size = sizeof(char) * square * square + 1;
	if (!display)
	{
		display = (char*)ft_memalloc(size);
		display = (char*)ft_memset(display, '*', size - 1); //'*' a verifier
	}
	//p == numero de la lettre
	//t == le tetri a scanner pour savoir ou mettre les cubes
	//c == ou le mettre dans la map (display)
	i = t.y;
	p = p + 65;
	while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x | (diplay[c.y + i]))) // faire un par un
	{
		diplay[c.y + i] = p;
		--i;
	}
}

int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;

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
				ft_display(square, t, p, c);
				return (0);
			}
		}
		if (c.x + t[p].x >= square && !(c.x = 0))
			++c.y;
	}
	return (1);
}
