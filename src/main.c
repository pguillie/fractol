/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:40:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 18:55:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

static int	ft_keyboard_event(int key, t_mlx m)
{
	(void)m;
	
	if (key == 53)
		exit (EXIT_SUCCESS);
	return (0);
}

int			main(int ac, char *av[])
{
	t_mlx	m;

	if (ft_mlx_init(&m, ac, av) < 0)
		return (EXIT_FAILURE);
	ft_mandelbrot(m.img);
	//ft_julia(m.img);
	mlx_put_image_to_window(m.mlx, m.win, m.img.ptr, 0, 0);
	mlx_mouse_hook(m.win, ft_mouse_event, &m);
	mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, ft_keyboard_event, &m);
	mlx_loop(m.mlx);
	return (EXIT_SUCCESS);
}	
