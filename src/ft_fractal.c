/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:39:38 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 13:58:12 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_fractal(t_win w)
{
	double	c[2];
	double	z[2];
	int		p[2];
	int		i[2];

	i[0] = 50 + w.zoom * 0.2;
	p[0] = 0;
	while (p[0] < w.wdt)
	{
		p[1] = 0;
		while (p[1] < w.hgt)
		{
			w.init_seq(c, z, p, w);
			i[1] = w.sequence(c, z, i[0]);
			w.str[p[1] * w.lsz + p[0] * w.bpp / 8 + 1] = i[1] * 0xFF / i[0];
			p[1]++;
		}
		p[0]++;
	}
}
