/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:20:11 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/30 18:33:13 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int c;
	int r;

	c = 1;
	r = 1;
	while (c <= nb)
	{
		r = ft_pow(c);
		if (r == nb)
			return (c);
		c++;
	}
	return (0);
}