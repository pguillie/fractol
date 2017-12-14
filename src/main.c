/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:40:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 16:46:32 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char *av[])
{
	t_mlx	m;

	if (ft_arg(ac, av, &m) < 0)
		return (EXIT_FAILURE);
	if ((m.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if (ft_init_j(&m))
		return (EXIT_FAILURE);
	if (ft_init_m(&m))
		return (EXIT_FAILURE);
	mlx_loop(m.mlx);
	return (EXIT_SUCCESS);
}
/*




	ft_mandelbrot(m.win[M]);
	ft_julia(m.win[J]);
	mlx_put_image_to_window(m.mlx, m.win[M].ptr, m.win[M].img, 0, 0);
	mlx_put_image_to_window(m.mlx, m.win[J].ptr, m.win[J].img, 0, 0);
	mlx_mouse_hook(m.win[M].ptr, ft_mouse_m, &m);
	mlx_hook(m.win[M].ptr, KEYPRESS, KEYPRESSMASK, ft_keyboard_m, &m);
	mlx_mouse_hook(m.win[J].ptr, ft_mouse_j, &m);
	mlx_hook(m.win[J].ptr, MOTIONNOTIFY, 0, ft_mouse_over, &m);
	mlx_hook(m.win[J].ptr, KEYPRESS, KEYPRESSMASK, ft_keyboard_j, &m);
	mlx_loop(m.mlx);
	return (EXIT_SUCCESS);
}*/	
