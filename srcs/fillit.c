#include "fillit.h"
#include <stdio.h>

void	begin(t_tetri *t)
{
	short		*map;
	int			square;
	int			p;
//	calcul carré minimum en fonction du nombre de pieces
	map = NULL;
	square = 4; //on fait * 2 direct
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

	p = 0;
//	si backtracking echec alors piece precedente a bouger => augmenter tailler carré minimum
	//bt = backtracking(t, square, map, p);
	/*if(bt > 0)
		backtracking(t, square, map, p + 1);
	else if (bt == 0)
	{
		backtracking(t, square * 2, map, p + 1);
	}*/
	while (0 < backtracking(t, square * 2, map, p));
}

int 	backtracking(t_tetri *t, int square, short *map, int p)
{
	t_coords	c;
	int i;

	i = 0;
	c.y = -1;
	c.x = -1;
	if (!map)
		map[13] = (short[13]){0};
	//comparaison binaire pour placer la piece
	//pas moyen de faire direct sans les boucles?
	//Manu : je comprend pas la question, pas assez precise et a quoi sert a la ligne d en dessous ?
	while (++c.y <= t->y) //pour chaque lignes du tetri
	{
		while (++c.x <= t->x)
		{
			//if((t[p]->data &= 0xF000 >> 4 * c.y))
			if((map[c.y][c.x] &= (t[p]->data & 0b1 << 16 - c.y))) //si 1 alors il y a un obstacle
				i = 1;
		}
	}
	//if (!i) //si toute la place est libre pour la piece
	//Manu : penser a checker si la piece + sa position est superieur a square, dans ce cas c est pas bon, pour savoir
	//en x : c.x + t->x <= square

		//map[] = t[p]->data;
	//backtracking(t, square, map, p + 1);
	printf("\ni = %d\n", i);
	return (0);
}
