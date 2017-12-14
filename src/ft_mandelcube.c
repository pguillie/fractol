/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelcube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:09:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 15:32:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelcube_seq(double c[2], double z[2], int max)
{
	double	t;
	int		i;

	double	a[2];

	i = 0;
	(void)t;
	(void)a;
	while (i < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
	//* burning ship
		a[0] = z[0];
		a[1] = (z[1] > 0 ? z[1] : -z[1]);
		z[0] = a[0] * a[0] - z[1] * z[1] + c[0];
		z[1] = 2 * a[0] * a[1] + c[1];
	//	*/
	/* mandelcube
		t = z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c[0];
		z[1] = 3 * z[0] * z[0] * z[1] - z[1] * z[1] * z[1] + c[1];
		z[0] = t;
		*/
	/* mandelbrot
		t = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = t;
		*/
		i++;
	}
	return (i);
}

void		ft_mandelcube(t_win w)
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
			z[0] = w.cur[0];
			z[1] = w.cur[1];
			c[0] = x / (w.wdt * w.zoom) - 0.5 / w.zoom + w.ctr[0];
			c[1] = y / (w.hgt * w.zoom) - 0.5 / w.zoom + w.ctr[1];
			w.str[y * w.lsz + x * w.bpp / 8 + 1] = ft_mandelcube_seq(c, z, i) * 0xFF / i;
			y++;
		}
		x++;
	}
}
