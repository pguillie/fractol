/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:37:14 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 15:16:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_julia_seq(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	i = 0;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = t;
		i++;
	}
	return (i);	
}

void		ft_julia(t_win w)
{
	double	c[2];
	double	z[2];
	int		x;
	int		y;
	int		i;

	i = 50 + w.zoom * 0.2;
	x = 0;
	while (x < w.wdt)
	{
		y = 0;
		while (y < w.hgt)
		{
			c[0] = w.cur[0];
			c[1] = w.cur[1];
			z[0] = x / (w.wdt * w.zoom) - 0.5 / w.zoom + w.ctr[0];
			z[1] = y / (w.hgt * w.zoom) - 0.5 / w.zoom + w.ctr[1];
			w.str[y * w.lsz + x * w.bpp / 8 + 1] = ft_julia_seq(c, z, i) * 0xFF / i;
			y++;
		}
		x++;
	}
}
