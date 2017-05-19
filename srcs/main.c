/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:03:58 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/19 07:01:26 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char	*file_content;
	t_tetri	t[26];
	int i;
	int	j;

	if (argc != 2)
	{
		write(1, "usage: ./fillit tetriminos_file\n", );
		return (0);
	}
	file_content = read_file(argv[1]);
	if (!parse_file(file_content, t))
		return (0);
	if (!set_tetri(t))
		return (0);
	if (!(check_tetris(&t)))
		return (0);
	recup_tetris_min(&t);
	j = -1;
	while(++j < t.nb)
	{
		i = -1;
		while (++i < 16)
		{
			ft_putnbr(t.tetris_min[j][i]);
			if (!((i + 1) & 3))
				ft_putchar('\n');
		}
		ft_putchar('\n');
	}
	return (0);
}
