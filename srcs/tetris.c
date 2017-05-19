#include "fillit.h"

int		check_tetri(t_tetri *t, int k, int j, int four)
{
	int	i;
	int	connect;

	i = -1;
	while (++i < 16)
	{
		if (t[j]->tetriminos[i] && ++four)
		{
			connect = 0;
			if (((i + 1) % 4) && t->tetriminos[j][i + 1])
				++connect;
			if ((i % 4) && t->tetriminos[j][i - 1])
				++connect;
			if ((i > 3) && t->tetriminos[j][i - 4])
				++connect;
			if ((i < 12) && t->tetriminos[j][i + 4])
				++connect;
			if (connect == 2)
				k = 1;
			else if (!connect)
				return (0);
		}
	}
	return ((!k || four != 4) ? 0 : 1);
}

int		check_tetris(t_tetri *t)
{
	int	j;
	int	k;
	int four;

	j = -1;
	while(++j < t->nb)
	{
		k = 0;
		four = 0;
		if (!check_tetri(t, k, j, four))
			return (0);
	}
	return (1);
}
