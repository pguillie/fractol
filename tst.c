#include "mlx.h"

int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	char *adr;
	int  info[3];

	mlx = mlx_init();
	img = mlx_new_image(mlx, 100, 100);
	adr = mlx_get_data_addr(img, info, info + 1, info + 2);
	int i;
	int j;
	printf("bpp: %d ; sline: %d ; endian: %d\n", info[0], info[1], info[2]);
	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100 * info[0] / 8)
		{
			adr[i * info[1] + j] = 0xFF;
			adr[i * info[1] + j + 2] = 0xFF;
			j += info[0] / 8;
		}
		i++;
	}
	win = mlx_new_window(mlx, 200, 200, "TEST");
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}
