/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmp_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 05:37:02 by jjourne           #+#    #+#             */
/*   Updated: 2017/06/02 08:29:45 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		cmp_map(short *map, short tdata, int x, int y, int ty)
{
	int i;

	i = ty;
	printf("iteration begin : %d\n", i);
//	while (i != -1 && !((((0xF000 >> (i * 4)) & tdata) >> x) & (map[y + i])))
	while (i != -1 && ((tdata << (i * 4) & 0xF) >> x & (map[y + i])))
		--i;
	if (((((0xF000 >> (i * 4)) & tdata) >> x) << (i * 4)) & (map[y + i]))
	{
		printf("end iteration : %d\n", i);
		return (0);
	}
	return (1);
}

int		main(void)
{
	int x = 6;
	int y = 2;
	int ty = 1;
	short map[6];
	short tdata;

	map[0] = 0x0000; //0111111111111111 = 0x7FFF
	map[1] = 0x0000; //0011111111111111 = 3FFF
	map[2] = 0x0000;
	map[3] = 0x0000;
	map[4] = 0x0000;
	map[5] = 0x0000; //1011111111111111 = BFFF

	//tdata = 0x8C40;
	tdata = 0x4E00;
	//1000
	//1100
	//0100
	//0000

	printf("test fonction : \n");
	if(cmp_map(map, tdata, x, y, ty))
		printf("la piece peut etre pose !");
	else
		printf("impossible de poser la piece !");
	return (0);
}
