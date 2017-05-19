#include "fillit.h"

/*int    move_tetri(t_tetri *t, j)
{
    int i;
    int k;

    k = 0;
    i = -1;
    while (++i < 16)
    {
        if (t->tetriminos[j][i])
        {
            if(t->tetriminos[j][i] && )
        }
    }
    return (0);
}*/

void	recup_tetris_min(t_tetri *t)
{
	int i;
    int j;
    int k;
	int l;
	char	**tetris_min;

	tetris_min = (char **) malloc(sizeof(char*) * 26);
	i = 26;
	while (--i > -1)
		tetris_min[i] = (char *) malloc(sizeof(char) * 13);

	t->tetris_min = tetris_min;
    j = -1;
    while(++j < t->nb)
    {
        i = ((t->p[j].min.y * 4) + t->p[j].min.x);
        k = ((t->p[j].max.y * 4) + t->p[j].max.x);
		l = 0;

        /*printf("\ni : %d", i);
        printf("\nx min : %d", t->p[j].min.x);
        printf("\ny min : %d", t->p[j].min.y);

        printf("\n\nk : %d", i);
        printf("\nx max : %d", t->p[j].max.x);
        printf("\ny max : %d", t->p[j].max.y);

        printf("\ntetri nb : %d\n\n", j);*/

        while (i <= k)
        {
			t->tetris_min[j][l] = t->tetriminos[j][i];
            i++;
			l++;
        }
    }
}

/*
** k checks that the tetri has at least 1 piece connected to 2 other pieces
*/

int		check_tetri(t_tetri *t, int k, int j, int four)
{
	int	i;
	int	connect;

	i = -1;
	while (++i < 16)
	{
		if (t->tetriminos[j][i] && ++four)
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
        //if (!move_tetris(t, j))
        //    return (0);
        trim_piece(t, j);
        //ft_putnbr(t->p[j].min.x);
        ft_putchar('\n');
	}
	return (1);
}
