/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:42:46 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/11 17:08:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win[2];
	int		i;
	int		d[2];
	float	z[3];
	float	c[2];
	float	zoom[2];
	
	mlx = mlx_init();
	win[0] = mlx_new_window(mlx, 1000, 1000, "mandelbrot");
	zoom[0] = 1000 / (0.6 + 2.1);
	zoom[1] = 1000 / (1.2 + 1.2);
	d[0] = 0;
	while (d[0] < 1000)
	{
		d[1] = 0;
		while (d[1] < 1000)
		{
			i = 0;
			c[0] = d[0] / zoom[0] - 2.1;
			c[1] = d[1] / zoom[1] - 1.2;
			z[0] = 0;
			z[1] = 0;
			while (i < 50 && z[0] * z[0] + z[1] * z[1] < 20)
			{
				z[2] = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[2] * z[1] + c[1];
				i++;
			}
			if (i == 20)
				printf("(%d,%d)\n", d[0], d[1]);
			mlx_pixel_put(mlx, win[0], d[0], d[1], (i * 255 / 100) << 8);
			d[1]++;
		}
		d[0]++;
	}
	mlx_loop(mlx);
	return (0);
}
