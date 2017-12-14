/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:58:47 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 18:11:02 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include <stdio.h>
int		ft_mouse_j(int key, int x, int y, t_mlx *m)
{
	if (y < 0)
		return (1);
	if (key == BUTTON1)
		ft_move(&m->win[J], key, x, y);
	else if (key == BUTTON2)
		ft_pointer(&m->win[J], key, 0, 0);
	else if (key == BUTTON4 || key == BUTTON5)
		ft_zoom(&m->win[J], key, x, y);
	ft_julia(m->win[J]);
	mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0);
	return (0);
}

int		ft_mouse_m(int key, int x, int y, t_mlx *m)
{
	if (y < 0)
		return (1);
	if (key == BUTTON1)
		ft_move(&m->win[M], key, x, y);
	else if (key == BUTTON2)
		ft_pointer(&m->win[M], key, 0, 0);
	else if (key == BUTTON4 || key == BUTTON5)
		ft_zoom(&m->win[M], key, x, y);
	ft_mandelbrot(m->win[M]);
	mlx_put_image_to_window(m->mlx, m->win[M].ptr, m->win[M].img, 0, 0);
	return (0);
}

int		ft_pointer_j(int x, int y, t_mlx *m)
{
	ft_pointer(&m->win[J], 0, x, y);
	ft_julia(m->win[J]);
	mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0);
	return (0);
}

int		ft_pointer_m(int x, int y, t_mlx *m)
{
	ft_pointer(&m->win[M], 0, x, y);
	ft_mandelbrot(m->win[M]);
	mlx_put_image_to_window(m->mlx, m->win[M].ptr, m->win[M].img, 0, 0);
	return (0);
}

/* int		ft_mouse_m(int key, int x, int y, t_mlx *m) */
/* { */
/* 	if (y < 0) */
/* 		return (1); */
/* 	if (key == 5) */
/* 	{ */
/* 		m->win[M].ctr[0] = (m->win[M].ctr[0] + x / (m->win[M].wdt * m->win[M].zoom) */
/* 				- 0.5 / m->win[M].zoom + m->win[M].ctr[0]) / 2; */
/* 		m->win[M].ctr[1] = (m->win[M].ctr[1] + y / (m->win[M].hgt * m->win[M].zoom) */
/* 				- 0.5 / m->win[M].zoom + m->win[M].ctr[1]) / 2; */
/* 		m->win[M].zoom *= 2; */
/* 	} */
/* 	else if (key == 4) */
/* 	{ */
/* 		m->win[M].ctr[0] = 2 * m->win[M].ctr[0] - (x / (m->win[M].wdt * m->win[M].zoom) */
/* 				- 0.5 / m->win[M].zoom + m->win[M].ctr[0]); */
/* 		m->win[M].ctr[1] = 2 * m->win[M].ctr[1] - (y / (m->win[M].hgt * m->win[M].zoom) */
/* 				- 0.5 / m->win[M].zoom + m->win[M].ctr[1]); */
/* 		m->win[M].zoom /= 2; */
/* 	} */
/* 	if (key == MOUSE_L) */
/* 	{ */
/* 		m->win[M].ctr[0] = x / (m->win[M].wdt * m->win[M].zoom) - 0.5 / m->win[M].zoom + m->win[M].ctr[0]; */
/* 		m->win[M].ctr[1] = y / (m->win[M].wdt * m->win[M].zoom) - 0.5 / m->win[M].zoom + m->win[M].ctr[1]; */
/* 	} */
/* 	ft_mandelbrot(m->win[M]); */
/* 	mlx_put_image_to_window(m->mlx, m->win[M].ptr, m->win[M].img, 0, 0); */
/* 	return (0); */
/* } */

/* int		ft_mouse_j(int key, int x, int y, t_mlx *m) */
/* { */
/* 	if (y < 0) */
/* 		return (1); */
/* 	if (key == 5) */
/* 	{ */
/* 		m->win[J].ctr[0] = (m->win[J].ctr[0] + x / (m->win[J].wdt * m->win[J].zoom) */
/* 				- 0.5 / m->win[J].zoom + m->win[J].ctr[0]) / 2; */
/* 		m->win[J].ctr[1] = (m->win[J].ctr[1] + y / (m->win[J].hgt * m->win[J].zoom) */
/* 				- 0.5 / m->win[J].zoom + m->win[J].ctr[1]) / 2; */
/* 		m->win[J].zoom *= 2; */
/* 	} */
/* 	else if (key == 4) */
/* 	{ */
/* 		m->win[J].ctr[0] = 2 * m->win[J].ctr[0] - (x / (m->win[J].wdt * m->win[J].zoom) */
/* 				- 0.5 / m->win[J].zoom + m->win[J].ctr[0]); */
/* 		m->win[J].ctr[1] = 2 * m->win[J].ctr[1] - (y / (m->win[J].hgt * m->win[J].zoom) */
/* 				- 0.5 / m->win[J].zoom + m->win[J].ctr[1]); */
/* 		m->win[J].zoom /= 2; */
/* 	} */
/* 	else if (key == MOUSE_L) */
/* 	{ */
/* 		m->win[J].ctr[0] = x / (m->win[J].wdt * m->win[J].zoom) - 0.5 / m->win[J].zoom + m->win[J].ctr[0]; */
/* 		m->win[J].ctr[1] = y / (m->win[J].wdt * m->win[J].zoom) - 0.5 / m->win[J].zoom + m->win[J].ctr[1]; */
/* 	} */
/* 	else if (key == MOUSE_R) */
/* 		m->win[J].cur[2] = (int)(m->win[J].cur[2] + 1) % 2; */
/* 	ft_julia(m->win[J]); */
/* 	mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0); */
/* 	return (0); */
/* } */

/* int		ft_mouse_over(int x, int y, t_mlx *m) */
/* { */
/* 	if (m->win[J].cur[2] == 0) */
/* 		return (1); */
/* 	m->win[J].cur[0] = x / (m->win[J].wdt / 2.0) - 1; */
/* 	m->win[J].cur[1] = y / (m->win[J].hgt / 2.0) - 1; */
/* 	ft_julia(m->win[J]); */
/* 	mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0); */
/* 	return (0); */
/* } */

/*
   int		ft_mouse_m(int key, int x, int y, t_mlx *m)
   {
//printf("key = %d, x = %d, y = %d\n", key, x, y);
if (y < 0)
return (1);
if (key == 1)
{
m->win[M].ctr[0] = (m->win[M].ctr[0] + x / (m->win[M].wdt * m->win[M].zoom)
- 0.5 / m->win[M].zoom + m->win[M].ctr[0]) / 2;
m->win[M].ctr[1] = (m->win[M].ctr[1] + y / (m->win[M].hgt * m->win[M].zoom)
- 0.5 / m->win[M].zoom + m->win[M].ctr[1]) / 2;
m->win[M].zoom *= 2;
}
else if (key == 2)
{
m->win[M].ctr[0] = 2 * m->win[M].ctr[0] - (x / (m->win[M].wdt * m->win[M].zoom)
- 0.5 / m->win[M].zoom + m->win[M].ctr[0]);
m->win[M].ctr[1] = 2 * m->win[M].ctr[1] - (y / (m->win[M].hgt * m->win[M].zoom)
- 0.5 / m->win[M].zoom + m->win[M].ctr[1]);
m->win[M].zoom /= 2;
}
ft_mandelbrot(m->win[M]);
mlx_put_image_to_window(m->mlx, m->win[M].ptr, m->win[M].img, 0, 0);
return (0);
}

int		ft_mouse_j(int key, int x, int y, t_mlx *m)
{
//printf("key = %d, x = %d, y = %d\n", key, x, y);
if (y < 0)
return (1);
if (key == 1)
{
m->win[J].ctr[0] = (m->win[J].ctr[0] + x / (m->win[J].wdt * m->win[J].zoom)
- 0.5 / m->win[J].zoom + m->win[J].ctr[0]) / 2;
m->win[J].ctr[1] = (m->win[J].ctr[1] + y / (m->win[J].hgt * m->win[J].zoom)
- 0.5 / m->win[J].zoom + m->win[J].ctr[1]) / 2;
m->win[J].zoom *= 2;
}
else if (key == 2)
{
m->win[J].ctr[0] = 2 * m->win[J].ctr[0] - (x / (m->win[J].wdt * m->win[J].zoom)
- 0.5 / m->win[J].zoom + m->win[J].ctr[0]);
m->win[J].ctr[1] = 2 * m->win[J].ctr[1] - (y / (m->win[J].hgt * m->win[J].zoom)
- 0.5 / m->win[J].zoom + m->win[J].ctr[1]);
m->win[J].zoom /= 2;
}
ft_julia(m->win[J]);
mlx_put_image_to_window(m->mlx, m->win[J].ptr, m->win[J].img, 0, 0);
return (0);
}
*/
