#include "fillit.h"
#include <stdio.h>

void	begin(t_tetri *t, int rd)
{
	short		*map;
	int			square;

	map = NULL;
	square = ft_sqrt((rd + 1) / 21 * 4);
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

void	put_tetri(short *map, t_coords c, t_tetri t)
{
	int i;

	i = t.y;
	while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x | (map[c.y + i])))
		--i;
}

void	rmv_tetri(short *map, t_coords c, t_tetri t)
{
	int i;

	i = t.y;
	while (i != -1 && ((t.data << (i * 4) & 0xF) >> c.x ^ (map[c.y + i])))
		--i;
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
			put_tetri(map, c, t[p]);
			if ((backtracking(t, square, map, p + 1)) && ++c.x)
				rmv_tetri(map, c, t[p]);
			else
			{
				//affiche_ma_putain_de_lettre(map, p, c);
				return (0);
			}
		}
		if (c.x + t[p].x >= square && !(c.x = 0))
			++c.y;
	}
	return (1);
}
