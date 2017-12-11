/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:40:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/11 17:18:11 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char *av[])
{
	void	*mlx;
	void	*win;
	void	*mndl;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "mandelbrot");
	mndl = ft_mandelbrot(mlx, win, 1000, 1000);
	mlx_put_image_to_window(mlx, win, mndl, 0, 0);
	mlx_loop(mlx);
	return (0);
}
