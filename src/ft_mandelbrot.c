/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:23:39 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 14:13:34 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mandelbrot2(double c, double z, int max)
{
	double	t;
	int		i;

	i = 0;
	while (i++ < max && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = t;
	}
	return (i);
}

void	ft_mandelbrot(char *addr, int bpp, int line_size, int endian, int center, int dim[2], int zoom)
{
	double	c[2];
	double	z[2];
	int		p[2];
	int		i;

	i = 5;
	p[0] = 0;
	while (p[0] < dim[0])
	{
		p[1] = 0;
		while (p[1] < dim[1])
		{
			ft_memset(z, 0, sizeof(double) * 2);
			c[0] = ;
			c[1] = ;
			if (ft_mandelbrot2(c, z, i) == i)
				ft_pixel();
			p[1]++;
		}
		p[0]++;
	}
}

/*
void	*ft_mandelbrot(void *mlx, int w, int h)
{
	void	*mndl;
	char	*addr;
	int bpp;
	int sline;
	int endian;

	mndl = mlx_new_image(mlx, w, h);
	addr = mlx_get_data_addr(mndl, &bpp, &sline, &endian);

	int iteration = 5;
	int infinite = 2;
	int i;
	int x;
	int y;
	float zoom = 3;
	float c[2];
	float z[3];

	float zpt[2] = {0, 2};
	
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
//			c[0] = x / ((w < h ? w : h) / (0.6 + 2.1)) - 2.1;
//			c[1] = y / ((w < h ? w : h) / (1.2 + 1.2)) - 1.2;
			c[0] = x / (w / (4.0 / zoom)) - 2.0 / zoom - zpt[0];

			c[0] = x / (w / (4.0 / zoom)) - 2.0 / zoom - zpt[0] + zpt[0] / powf(2, zoom - 1);
			c[1] = y / (h / (4.0 / zoom)) - 2.0 / zoom - zpt[1] + zpt[1] / powf(2, zoom - 1);
			z[0] = 0;
			z[1] = 0;
			i = 0;
			while (i < iteration && z[0] * z[0] + z[1] * z[1] < infinite)
			{
				z[2] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[0] * z[1] + c[1];
				z[0] = z[2];
				i++;
			}
			if (i < iteration)
			{
				addr[y * sline + x * bpp / 8 + 2] = i * 0xFF / iteration;
				addr[y * sline + x * bpp / 8 + 1] = i * 0x42 / iteration;
			}
			if (c[0] == 0 && c[1] == -1)//(int)(c[1] * 100) == -150)
				addr[y * sline + x * bpp / 8] = 0xFF;
			y++;
		}
		x++;
	}
	return (mndl);
}
*/
