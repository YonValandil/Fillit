/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:22:06 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/19 10:25:14 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_tetri(t_tetri *t)
{
	int		i;

	i = -1;
	while (++i < 26)
	{
		t[i]->x = 0;
		t[i]->y = 0;
		while (!(t[i]->data &= 0xF << 12))
			t[i]->data = t[i]->data << 4;
		while (!(t[k]->data &= 0x8888))
			t[i]->data << t[i]->data = 1;
		while (t[i]->data & 0x8888 >> t[i]->x)
			t[i]->x++;
		while (t[i]->data & 0xF000 >> t[i]->y)
			t[i]->y++;
	}
}

int		parse_file(char *file_content, t_tetri *t)
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
			if ((((i + 1) % 5) && file_content[i + 21 * k] != '.'
				&& file_content[i + 21 * k] != '#')
				|| (!((i + 1) % 5) && file_content[i + 21 * k] != '\n'))
				return (0);
			if ((i + 1) % 5)
				t[k]->data |= ((46 - file_content[i + 21 * k]) / 11) << --j;
		}
		if (file_content[i + 21 * k] == '\n')
			++k;
		else
			return (1);
	}
	return (0);
}

char	*read_file(char *file)
{
	int		rd;
	int		fd;
	char	*buf;

	buf = (char[BUFF_SIZE + 1]){0};
	if (-1 != (fd = open(file, O_RDONLY)) &&
			-1 != (rd = read(fd, buf, BUFF_SIZE)))
		rd = read(fd, buf, BUFF_SIZE);
	else
		write(1, "error\n", 6);
	return (buf);
}
