/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:03:58 by jjourne           #+#    #+#             */
/*   Updated: 2017/07/19 04:22:11 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		parse_file(char *buf, t_tetri *t)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k < 26)
	{
		t[k].data = 0;
		j = 16;
		i = -1;
		while (++i < 20)
		{
			if ((((i + 1) % 5) && buf[i + 21 * k] != '.'
						&& buf[i + 21 * k] != '#')
					|| (!((i + 1) % 5) && buf[i + 21 * k] != '\n'))
				return (0);
			if ((i + 1) % 5)
				t[k].data |= ((46 - buf[i + 21 * k]) / 11) << --j;
		}
		if (buf[i + 21 * k] == '\n')
			++k;
		else
			return (1);
	}
	return (0);
}

int		set_tetri(t_tetri *t, int nb)
{
	int		i;

	i = -1;
	while (++i < nb && t[i].data)
	{
		//t[i].nb = nb;
		t[i].x = 0;
		t[i].y = 0;
		while (!(t[i].data & 0xF000))
			t[i].data = t[i].data << 4;
		while (!(t[i].data & 0x8888))
			t[i].data = t[i].data << 1;
		if (t[i].data != T1 && t[i].data != T2 && t[i].data != T3 &&
				t[i].data != T4 && t[i].data != T5 && t[i].data != T6 &&
				t[i].data != T7 && t[i].data != T8 && t[i].data != T9 &&
				t[i].data != T10 && t[i].data != T11 && t[i].data != T12 &&
				t[i].data != T13 && t[i].data != T14 && t[i].data != T15 &&
				t[i].data != T16 && t[i].data != T17 && t[i].data != T18 &&
				t[i].data != T19)
			return (0);
		while (t[i].data & (0x8888 >> t[i].x))
			++t[i].x;
		while (t[i].data & (0xF000 >> (t[i].y * 4)))
			++t[i].y;
	}
	return ((!t[i].data && i < nb) ? 0 : 1);
}

int		main(int argc, char *argv[])
{
	int		rd;
	int		fd;
	char	*buf;
	t_tetri	t[26];

	rd = 1;
	if (argc != 2)
	{
		write(1, "usage: ./fillit tetriminos_file\n", 32);
		return (0);
	}
	buf = (char[BUFF_SIZE + 1]){0};
	if (-1 == (fd = open(argv[1], O_RDONLY)) ||
			-1 == (rd = read(fd, buf, BUFF_SIZE)) ||
			545 < rd || !parse_file(buf, t) ||
			!set_tetri(t, (rd = (rd + 1) / 21)))
	{
		ft_putstr("error\n");
		return (0);
	}
	begin(t, rd);
	return (0);
}
