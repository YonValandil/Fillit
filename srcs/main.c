/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:03:58 by jjourne           #+#    #+#             */
/*   Updated: 2017/06/03 05:06:40 by eferrand         ###   ########.fr       */
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

int     check_tetri(t_tetri *t)
{
	int i;
	int j;
	int four;
	int connect;

	j = -1;
	while (++j < 26 && (i = -1) &&
		!(four = 0))
		while (++i < 16)
			if ((t[j].data & (1 << i)) && ++four && !(connect = 0))
			{
				if (i < 16 && (t[j].data & (1 << (i + 1))) && t[j].data)
					++connect;
				if (i < 12 && (t[j].data & (1 << (i + 4))) && t[j].data)
					++connect;
				if (0 < i && (t[j].data & (1 << (i - 1))) && t[j].data)
					++connect;
				if (3 < i && (t[j].data & (1 << (i - 4))) && t[j].data)
					++connect;
				if ((!connect) || (four != 4 && i == 15))
					return (0);
			}
	printf("\ncheck\nfour  = %d\n\n", four);
	return ((four != 4) ? 0 : 1);
}

int		set_tetri(t_tetri *t)
{
	int		i;

	i = -1;
	while (++i < 26)
	{
		t[i].x = 0;
		t[i].y = 0;
		while (!(t[i].data &= 0xF << 12))
			t[i].data = t[i].data << 4;
		while (!(t[i].data &= 0x8888))
			t[i].data = t[i].data << 1;
		while (t[i].data & 0x8888 >> t[i].x)
			t[i].x++;
		while (t[i].data & 0xF000 >> t[i].y)
			t[i].y++;
	}
	printf("\nset tetri\n\n");
	return (1);
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
	if (-1 != (fd = open(*argv, O_RDONLY)) &&
		-1 != (rd = read(fd, buf, BUFF_SIZE)))
	if (buf[545] != '\0' || !parse_file(buf, t) || !set_tetri(t) || !check_tetri(t))
	{
		ft_putstr("error\n");
		return (0);
	}
	//begin(t, rd);
	return (0);
}
