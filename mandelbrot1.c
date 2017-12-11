#include "mlx.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		d[2];
	float	z[3];
	float	c[2];
	float	zoom[2];
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 270, 240, "mandelbrot");
	zoom[0] = 270 / (0.6 + 2.1);
	zoom[1] = 240 / (1.2 + 1.2);
	d[0] = 0;
	while (d[0] < 270)
	{
		d[1] = 0;
		while (d[1] < 240)
		{
			i = 0;
			c[0] = d[0] / zoom[0] - 2.1;
			c[1] = d[1] / zoom[1] - 1.2;
			z[0] = 0;
			z[1] = 0;
			while (i < 50 && z[0] * z[0] + z[1] * z[1] < 10000000000000000000)
			{
				z[2] = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[2] * z[1] + c[1];
				i++;
			}
			mlx_pixel_put(mlx, win, d[0], d[1], (i * 255 / 50) << 8);
			d[1]++;
		}
		d[0]++;
	}
	mlx_loop(mlx);
	return (0);
}
