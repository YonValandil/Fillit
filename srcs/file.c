/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:22:06 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/08 04:06:27 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
int		check_file(char *file_content)
{
	int i;
	int j;
	int k;
	int t;

	i = 0;
	t = 0;
	while (file_content[i] != '\0')
	{
		printf("\nnew tetri\n");
		k = 0;
		while (k < 4)
		{
			j = 0 + t;
			while(j < 4 + t)
			{
				if (file_content[j] != '.' && file_content[j] != '#')
				{
					printf("\ncaract ./# faux: %c", file_content[j]);
					return (0);
				}
				printf("\ncaract ./# juste: %c", file_content[j]);
				j++;
			}
			if (file_content[j] != '\n')
			{
				printf("\nfaux, pas de '\\n' apres ligne\n");
				return (0);
			}
			printf("\njuste, '\\n' apres ligne\n");
			printf("\nligne ok");
			t += 5;
			k++;
		}

		printf("\nformat tetri ok\n");

		if (file_content[t] == '\0')
		{
			printf("\nfile juste\n");
			return (1);
		}

		if (file_content[t] != '\n')
		{
			printf("\nfaux, pas de \\n ou \\0 apres tetri");
			printf("\n caract = %d\n", file_content[t]);
			return (0);
		}

		printf("\\n ou \\0 apres tetri ok\n");
		t++;
		i++;
	}
	return (1);
}
*/

int		parse_file(char *file_content, char ***tetriminos)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k < 26)
	{
		j = -1;
		i = -1;
		while (++i < 20)
		{
			if ((((i + 1) % 5) && file_content[i + 21 * k] != '.'
				&& file_content[i + 21 * k] != '#')
				|| (!((i + 1) % 5) && file_content[i + 21 * k] != '\n'))
				return (0);
			if ((i + 1) % 5)
				(*tetriminos)[k][++j] = (46 - file_content[i + 21 * k]) / 11;
		}
		if (file_content[i + 21 * k] == '\n')
			++k;
		else
			return ((file_content[i + 21 * k] == '\0') ? k + 1 : 0);
	}
	return (0);
}

char	*read_file(char *file)
{
	int rd;
	int fd;
	char *buf;

	rd = 1;
	buf = ft_memalloc(sizeof(char) * (BUF_SIZE + 1));
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		while (rd > 0)
		{
			rd = read(fd, buf, BUF_SIZE);
			buf[rd] = '\0';
			return (buf);
		}
	}
	else
		write(2, "Open fd failed\n", 15);
	if (close(fd))
		write(2, "file close failed\n", 18);
	return (0);
}
