/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eferrand <eferrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 05:06:56 by eferrand          #+#    #+#             */
/*   Updated: 2017/09/04 04:18:41 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_bin(unsigned short nb, int square)
{
	int	a;

	a = 16;
	while (a--)
	{
		if (a + square < 16)
			break ;
		ft_putnbr((nb & (1 << a)) != 0);
		write(1, " ", 1);
	}
	printf("\n");
}

void	begin(t_tetri *t, int nb)
{
	short		*map;
	int			square;
	int 		p;

	p = 0;
	map = NULL;
	square = ft_sqrt(nb * 4);
	printf("nb = %d\nsquare = %d\n\n", nb, square);
	while (0 < backtracking(t, square, map, p))
	{
		++square;
		printf("\nbegin square = %d\n\n", square);
	}
}

int		cmp_map(short *map, t_coords c, t_tetri t)
{
	int i;

	i = t.y;
	printf("cmp_map t.x = %d	t.y = %d\n", t.x, t.y);
	while (i != -1 && !((t.data << (i * 4) & 0xF000) >> c.x & map[c.y + i]))
		--i;
	if (i != -1)
		return (0);
	return (1);
}

void	operand_tetri(short *map, t_coords c, t_tetri t, int flag)
{
	int i;

	i = t.y - 1;
	if (flag == PUT)
	{
		printf("PUT :\nc.x = %d\nc.y = %d\n", c.x, c.y);
		while (0 <= i) 
		{
			map[c.y + i] |= (t.data << (i * 4) & 0xF000) >> c.x;
			--i;
		}
	}
	else if (flag == REMOVE)
	{
		printf("REMOVE :\nc.x = %d\nc.y = %d\n", c.x, c.y);
		while (0 <= i)
		{
			map[c.y + i] ^= (t.data << (i * 4) & 0xF000) >> c.x;
			--i;
		}
	}
}

void	ft_display(int square, t_tetri *t, int p, t_coords c)
{
	unsigned short	a;
	static char		*display = NULL;

	printf("coucou je display\n");
	if (!display)
	{
		if (!(display = (char*)malloc((square + 1) * square + 1)))
		{
			ft_putstr("error allocation\n");
			exit(3);
		}
		display = (char*)ft_memset(display, '.', (square + 1) * square);
		a = 0;
		while (display[a])
		{
			if (!((a + 1) % (square + 1)))
				display[a] = '\n';
			++a;
		}
	}
	// ça deconne à partir d'ici
	a = 0;
	while (a < 16)
	{ 
		if (t->data & (1 << a))
			display[c.x + (c.y + a / 4) * (square + 1) + a % 4] = p + 'A';
		++a;
	}
	if (p == 0)
	{
		ft_putstr(display);
		exit(3);
	}
}

void	print_map(short *map, int square)
{
	(void)map;
	int i;

	i = 0;
	while(i < square)
	{
		print_bin(map[i], square);
		i++;
	}
	printf("\n");
}

int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;

	printf("|____________________________________________________________________|\np = %d\n\n", p);
	c.x = 0;
	c.y = 0;
	if (!map)
		map = (short[13]){0};
	while (c.y + t[p].y <= square)
	{
		while (c.x + t[p].x <= square && !cmp_map(map, c, t[p]))
			++c.x;
//		printf("entré dans le if put remove : %d\nc.x + t[p].x <= square\nc.x = %d\nt[p].x = %d\nsquare = %d\n\n", c.x + t[p].x <= square, c.x, t[p].x, square);
//		sleep(1);
		if (c.x + t[p].x <= square)
		{
			operand_tetri(map, c, t[p], PUT);
			printf("piece :%hx\nmap :\n", t[p].data);
			print_map(map, square);
//			sleep(1);
			if ((t[p].data) && (backtracking(t, square, map, p + 1)))
			{
				operand_tetri(map, c, t[p], REMOVE);
				printf("piece :%hx\nmap :\n", t[p].data);
				print_map(map, square);
//				sleep(1);
				++c.x;
			}
			else
			{
				ft_display(square, t, p, c);
				return (0);
			}
		}
		else if (!(c.x = 0))
			++c.y;
	}
	return (1);
}
