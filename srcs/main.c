/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:03:58 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/23 06:09:39 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char	*file_content;
	t_tetri	t[26];

	if (argc != 2)
	{
		write(1, "usage: ./fillit tetriminos_file\n", 32);
		return (0);
	}
	file_content = read_file(argv[1]);
	if (!parse_file(file_content, t) || !set_tetri(t) || !check_tetri(t))
		return (0);
	begin(t);
	return (0);
}
