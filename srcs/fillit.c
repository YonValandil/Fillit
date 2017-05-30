#include "fillit.h"
#include <stdio.h>

void	begin(t_tetri *t, int rd)
{
	short		*map;
	int			square;

	map = NULL;
	square = ft_sqrt((rd + 1) / 21 * 4);

	//je prend pour une piece au commencement parce qu'en fait on a pas le nbr de pieces totals
	/* Note de Manu :
** Square doit posseder la taille minimum du coté de la carte en fonction du nombre de piece
** 1 piece = 4 cubes
** donc Aire de Square  =  (nombre de piece * 4) et la on obtient l aire
** Pour calculer l aire d un carré (car notre carte sera toujours un carré)
** On multiplie le coté par lui meme soit : pow(coté, 2)
** pow correspond a la fonction mathematique puissance
**
** A partir de la tu devrais pouvoir finir la formule
** L evolution de square se fait de 1 par 1 et non pas *2
** square = square + 1
*/

//	si backtracking echec alors piece precedente a bouger => augmenter tailler carré minimum

	//bt = backtracking(t, square, map, p);
	/*if(bt > 0)
		backtracking(t, square, map, p + 1);
	else if (bt == 0)
	{
		backtracking(t, square * 2, map, p + 1);
	}*/
	while (0 < backtracking(t, square++, map, 0))
		;
}

int		cmp_map(short *map, t_coords c, t_tetri t)
{
// premiere ligne de la piece ne sont que les 4 premiers bits du short de la piece
// premiere ligne de la map est un short entier
// comparaison a l aide de &
// le defi est disoler les informations qui nous interessent pour ne pas etre
// parasité par l obsolete

	map[c.y]
	map[c.y + 1]
	map[c.y + 2]
	map[c.y + 3]

	int i;

	i = -1;
	while ((i / 4) < t.x)
	{
		if((t.data & (0xF << 12 - i)) & (map[c.y] & (0xF000 >> c.x)))
		{
			return (0);
		}
		i += 4;
	}
	return (1);
}

int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;

	c.y = -1;
	if (!map)
		map = (short[13]){0};
	//est ce que je suis oblige de parcourir toute la map (un a un) avec les boucles ?
	//Ou est qu'il y a un moyen de comparer un block entier et non pas caractere par caractere
	//Manu : je comprend pas la question, pas assez precise et a quoi sert a la ligne d en dessous ?
	while (++c.y + t[p].y < square)
	{
		c.x = -1;
		while (++c.x + t[p].x < square && cmp_map(map, c, t[p]) != 0)
		{
			++c.x;
		}
	}
	if (sortir)
	//si toute la place est libre pour le tetri et qu'il depasse pas on peut poser la piece
	//if (!i && (map[c.y] + t->x <= square))
	//Manu : penser a checker si la piece + sa position est superieur a square, dans ce cas c est pas bon, pour savoir
	//en x : c.x + t->x <= square

		//map[] = t[p]->data;
	//backtracking(t, square, map, p + 1);
	return (0);
}
