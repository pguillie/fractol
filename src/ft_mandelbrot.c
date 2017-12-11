/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:23:39 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/11 17:34:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_mandelbrot(void *mlx, void *win, int w, int h)
{
	void	*mndl;
	char	*addr;
	int bpp;
	int sline;
	int endian;

	mndl = mlx_new_image(mlx, w, h);
	addr = mlx_get_data_addr(mndl, &bpp, &sline, &endian);

	int iteration = 50;
	int infinite = 10;
	int i;
	int x;
	int y;
	float zoom = 1;
	float c[2];
	float z[3];
	
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			c[0] = x / ((w < h ? w : h) / (0.6 + 2.1)) - 2.1;
			c[1] = y / ((w < h ? w : h) / (1.2 + 1.2)) - 1.2;
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
			y++;
		}
		x++;
	}
	return (mndl);
}
