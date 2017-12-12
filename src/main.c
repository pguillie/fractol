/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:40:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 14:23:33 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char *av[])
{
	t_mlx	m;

	if (ft_mlx_init(m, ac, av) < 0)
		return (EXIT_FAILURE);
	m.img = ft_mandelbrot(m);
	mlx_put_image_to_window(m.mlx, m.win. m.img, 0, 0);
	mlx_loop();
	return (EXIT_SUCCESS);
}	
/*
	mlx = mlx_init();
	mndl = ft_mandelbrot(mlx, 1000, 1000);
	win = mlx_new_window(mlx, 1000, 1000, "mandelbrot");
	mlx_put_image_to_window(mlx, win, mndl, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
