#include "fillit.h"

int		check_tetri(t_tetri *t)
{
	int	i;
	int	j;
	int	four;
	int	connect;

	i = -1;
	j = -1;
	four = 0;
	while (++j < 26)
		while (++i < 16)
			if ((t[j]->data & (1 << i)) && ++four)
			{
				connect = 0;
				if (i < 16 && (t[j]->data & (1 << (i + 1))) && t[j]->data)
					++connect;
				if (i < 12 && (t[j]->data & (1 << (i + 4))) && t[j]->data)
					++connect;
				if (0 < i && (t[j]->data & (1 << (i - 1))) && t[j]->data)
					++connect;
				if (3 < i && (t[j]->data & (1 << (i - 4))) && t[j]->data)
					++connect;
				if ((!connect) || (four != 4 && i == 15))
					return (0);
			}
	return ((four != 4) ? 0 : 1);
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
