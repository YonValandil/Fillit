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

void	begin(t_tetri *t, int nb)
{
	short		*map;
	int			square;
	int 		p;

	p = 0;
	map = NULL;
	square = ft_sqrt(nb * 4);
	while (0 < backtracking(t, square, map, p))
	{

		printf("\nbegin p = %d\n", p); //
		++square;
	}
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

void	operand_tetri(short *map, t_coords c, t_tetri t, int flag, int square) //tmp square
{
	int i;

	i = t.y;
	printf("\ndans operand tetri\n"); //
	printf("i = %d\n", i); //
	if (flag == PUT)
	{
		printf("\ndans PUT tetri\n"); //
		while (i >= 0 && ((map[c.y + i]) |= (t.data << (i * 4) & 0xF) >> c.x))
		{
			printf("\n----- put le tetri -----\n"); //
			//map[c.y + i] = (t.data << (i * 4) & 0xF) >> c.x | (map[c.y + i]);

			--i;
		}
		printf("\ndans PUT tetri square = %d\n", square); //
		printf("\nmap = \n"); //
		//------TEST AFF MAP FINAL (avec les 0/1)----------
		int i;
		i = 0;
		int j;
		j = -1;
		square = 13;
		while (++j < square || i < square)
		{
			if (!(j % square))
			{
				++i;
				j = 0;
				ft_putchar('\n');
			}
			ft_putchar(((map[i] << j) & 1) + '0');
		}
		printf("VIVE LES FLEURS\n");
		int	yoyo = 0;
		while (yoyo < 13)
		{
			ft_putchar(map[yoyo] + '0');
			++yoyo;
		}
		printf("yoyo\n");
		//--------------------------------------------
	}
	else if (flag == REMOVE)
	{
		while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x ^ (map[c.y + i])))
		{
			printf("\nremove tetri\n"); //
			--i;
		}
	}
}

void	ft_display(int square, t_tetri *t, int p, t_coords c) // old t_tetri t
{
	int i;
	int j;
	int size;
	static char *display = NULL;

	size = sizeof(char) * square * square + 1;
	if (!display)
	{
		display = (char*)ft_memalloc(size);
		display = (char*)ft_memset(display, '.', size - 1); //'.' a verifier
	}

	//ASSOCIATION DES LETTRES :

	//p == la lettre a afficher
	//t == le tetri a scanner pour savoir ou mettre les cubes
	//c == ou le mettre dans la map (display)

	//old : while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x | (diplay[c.y + i]))) //faire un par un

	i = -1;
	while (t[++i].data) // parcourir tous les tetris
	{
		j = 15;
		p = i + 65;
		c.x = 5; //tmp : juste pour utiliser la variable pour l'erreur de compil
		while (j != -1) // parcourir le tetri
		{
			//if () // Nawak : ((t[i].data << j) >> c.x & 0b1)
			//	display[] = p;
			--j;
		}
	}

	//AFFICHAGE DE LA MAP

	i = -1;
	while (display[++i])
	{
		if (!(i % square))
			ft_putchar('\n');
		ft_putchar(display[i]);
	}
}

int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;

	c.x = 0;
	c.y = 0;
	//if (p >= t[p].nb) //condition d'arret ajoute ligne 128, avant d'appeler bactrcking -> (t[p].data)
		//return (0);
	if (!map)
		map = (short[13]){0};
		//------TEST AFF MAP FINAL (avec les 0/1)----------
		int i;
		i = 0;
		int j;
		j = -1;
		square = 13;
		while (++j < square || i < square)
		{
			if (!(j % square))
			{
				++i;
				j = 0;
				ft_putchar('\n');
			}
			ft_putchar(((map[i] << j) & 1) + '0');
		}
		//--------------------------------------------
	//exit(0);
	printf("\npiece numero : %d\n", p); //
	printf("\ntetri = 0x%4X\n", t[p].data); //
	while (c.y + t[p].y < square)
	{
		while (c.x + t[p].x < square && !cmp_map(map, c, t[p]))
		{
			printf("\nc.x = %d\n", c.x); //
			++c.x;
		}
		if (c.x + t[p].x < square)
		{
			printf("\navant operand tetri pour put\n"); //
			operand_tetri(map, c, t[p], PUT, square); //square tmp

			if ((t[p].data) && (backtracking(t, square, map, p + 1)) && ++c.x)
			{
				printf("\nBACTRACKING : apres rappel\n"); //
				printf("\nsquare = %d, p = %d, c.x = %d, c.y = %d\n", square, p, c.x, c.y); //
				printf("\ntetri = 0x%4X\n", t[p].data); //
				operand_tetri(map, c, t[p], REMOVE, square); //square tmp
			}
			else
			{
				printf("\nAVANT ft_display, test aff map final :\n"); //

				//------TEST AFF MAP FINAL (avec les 0/1)----------
				int i;
				i = 0;
				int j;
				j = -1;
				square = 13;
				while (++j < square || i < square)
				{
					if (!(j % square))
					{
						++i;
						j = 0;
						ft_putchar('\n');
					}
					ft_putchar(((map[i] << j) & 1) + '0');
				}
				//--------------------------------------------

				//ft_display(square, t, p, c);
				printf("\nEND\n"); //
				return (0);
			}
		}
		if (c.x + t[p].x >= square && !(c.x = 0))
			++c.y;
	}
	return (1);
}
