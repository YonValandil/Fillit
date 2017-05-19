/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:03:58 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/01 20:49:43 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char	*file_content;
	char	**tetriminos;
	//char	**tetris_min;
	//char	*map;
	t_tetri	t;
	t_map	m;
	int i;
	int	j;

	if (argc == 2)
	{
		file_content = read_file(argv[1]);
	//	printf("\nfile : \n\n");
	//	ft_putstr(file_content);
	//	printf("\n---------------------------\n");
		tetriminos = (char **) malloc(sizeof(char*) * 26);
		//tetris_min = (char **) malloc(sizeof(char*) * 26);
		//tetriminos_min = (char **) malloc(sizeof(char*) * 26);
		i = 26;
		while (--i > -1)
		{
			tetriminos[i] = (char *) malloc(sizeof(char) * 16);
			//tetris_min[i] = (char *) malloc(sizeof(char) * 13);
			//tetriminos_min[i] = (char *) malloc(sizeof(char) * 10);
		}
		if (!(t.nb = parse_file(file_content, &tetriminos)))
			return (0);
		t.tetriminos = tetriminos;
		if (!(check_tetris(&t)))
			return (0);
		recup_tetris_min(&t);
		j = -1;
		while(++j < t.nb)
		{
			i = -1;
			while (++i < 16)
			{
				//ft_putnbr(t.tetriminos[j][i]);
				ft_putnbr(t.tetris_min[j][i]);
				if (!((i + 1) & 3)) // & n pareil que % (n + 1)
					ft_putchar('\n');
			}
			//ft_putnbr(t.p[j].min.x);
			ft_putchar('\n');
		}
		/*map = (char **) malloc(sizeof(char*) * t.nb);
		i = 26;
		while (--i > -1)
			map[i] = (char *) malloc(sizeof(char) * 16);
		*/
		//MAP
		resolv(&t, &m);
		m.map = (char *) malloc(sizeof(char) * t.nb);
		//m.map = filling_map(&t, &m);
	}
	else
		write(2, "not only 1 argument \n", 21);
	return (0);
}
