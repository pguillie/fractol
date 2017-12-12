/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:23:39 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 19:11:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot2(double c[2], double z[2], int max)
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

void	ft_mandelbrot(t_img img)
{
	double	c[2];
	double	z[2];
	int		x;
	int		y;
	int		i;

	i = 50 + img.zoom * 0.2;
	x = 0;
	while (x < img.width)
	{
		y = 0;
		while (y < img.height)
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = x / (img.width * img.zoom) - 0.5 / img.zoom + img.center[0];
			c[1] = y / (img.height * img.zoom) - 0.5 / img.zoom + img.center[1];
			img.addr[y * img.lsize + x * img.bpp / 8 + 1] = ft_mandelbrot2(c, z, i) * 0xFF / i;
			y++;
		}
		x++;
	}
}
