/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:58:47 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 18:36:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_event(int key, int x, int y, t_mlx *m)
{
	//printf("key = %d, x = %d, y = %d\n", key, x, y);
	if (key == 1)
	{
		m->img.center[0] = (m->img.center[0] + x / (m->img.width * m->img.zoom)
				- 0.5 / m->img.zoom + m->img.center[0]) / 2;
		m->img.center[1] = (m->img.center[1] + y / (m->img.height * m->img.zoom)
				- 0.5 / m->img.zoom + m->img.center[1]) / 2;
		m->img.zoom *= 2;
	}
	else if (key == 2)
	{
		m->img.center[0] = 2 * m->img.center[0] - (x / (m->img.width * m->img.zoom)
				- 0.5 / m->img.zoom + m->img.center[0]);
		m->img.center[1] = 2 * m->img.center[1] - (y / (m->img.height * m->img.zoom)
				- 0.5 / m->img.zoom + m->img.center[1]);
		m->img.zoom /= 2;
	}
	ft_mandelbrot(m->img);
	mlx_put_image_to_window(m->mlx, m->win, m->img.ptr, 0, 0);
	return (0);
}
