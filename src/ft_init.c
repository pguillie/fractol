/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:41:39 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 18:13:43 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_j(t_mlx *m)
{
	if (m->win[J].wdt == 0)
		return (0);
	if ((m->win[J].ptr = mlx_new_window(m->mlx, m->win[J].wdt,
					m->win[J].hgt, "Julia")) == NULL)
		return (-1);
	if ((m->win[J].img = mlx_new_image(m->mlx, m->win[J].wdt,
					m->win[J].hgt)) == NULL)
		return (-1);
	m->win[J].str = mlx_get_data_addr(m->win[J].img, &(m->win[J].bpp),
			&(m->win[J].lsz), &(m->win[J].edn));
	m->win[J].zoom = 0.2;
	m->win[J].ctr[0] = 0;
	m->win[J].ctr[1] = 0;
	m->win[J].cur[0] = -0.8;
	m->win[J].cur[1] = 0.2;
	m->win[J].cur[2] = 0;
	ft_julia(m->win[J]);
	mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0);
	mlx_mouse_hook(m->win[J].ptr, ft_mouse_j, m);
	mlx_hook(m->win[J].ptr, KEYPRESS, KEYPRESSMASK, ft_keyboard_j, m);
	mlx_hook(m->win[J].ptr, MOTIONNOTIFY, 0, ft_pointer_j, m);
	return (0);
}

int		ft_init_m(t_mlx *m)
{
	if (m->win[M].wdt == 0)
		return (0);
	if ((m->win[M].ptr = mlx_new_window(m->mlx, m->win[M].wdt,
					m->win[M].hgt, "Mandelbrot")) == NULL)
		return (-1);
	if ((m->win[M].img = mlx_new_image(m->mlx, m->win[M].wdt,
					m->win[M].hgt)) == NULL)
		return (-1);
	m->win[M].str = mlx_get_data_addr(m->win[M].img, &(m->win[M].bpp),
			&(m->win[M].lsz), &(m->win[M].edn));
	m->win[M].zoom = 0.3;
	m->win[M].ctr[0] = -0.65;
	m->win[M].ctr[1] = 0;
	m->win[M].cur[0] = 0;
	m->win[M].cur[1] = 0;
	m->win[M].cur[2] = 0;
	ft_mandelbrot(m->win[M]);
	mlx_put_image_to_window(m->mlx, m->win[M].ptr, m->win[M].img, 0, 0);
	mlx_mouse_hook(m->win[M].ptr, ft_mouse_m, m);
	mlx_hook(m->win[M].ptr, KEYPRESS, KEYPRESSMASK, ft_keyboard_m, m);
	mlx_hook(m->win[M].ptr, MOTIONNOTIFY, 0, ft_pointer_m, m);
	return (0);
}
