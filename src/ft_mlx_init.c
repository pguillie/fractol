/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:34 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 15:19:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mlx_init(t_mlx *m, int ac, char **av)
{
	(void)ac;
	(void)av;

	if ((m->mlx = mlx_init()) == NULL)
		return (-1);
	m->win[M].wdt = 1000;
	m->win[M].hgt = 1000;
	m->win[J].wdt = 1000;
	m->win[J].hgt = 1000;
	if ((m->win[M].ptr = mlx_new_window(m->mlx, m->win[M].wdt, m->win[M].hgt, "Mandelbrot")) == NULL)
		return (-1);
	if ((m->win[J].ptr = mlx_new_window(m->mlx, m->win[J].wdt, m->win[J].hgt, "Julia")) == NULL)
		return (-1);
	if ((m->win[M].img = mlx_new_image(m->mlx, m->win[M].wdt, m->win[M].hgt)) == NULL)
		return (-1);
	if ((m->win[J].img = mlx_new_image(m->mlx, m->win[J].wdt, m->win[J].hgt)) == NULL)
		return (-1);
	m->win[M].str = mlx_get_data_addr(m->win[M].img, &(m->win[M].bpp), &(m->win[M].lsz), &(m->win[M].edn));
	m->win[J].str = mlx_get_data_addr(m->win[J].img, &(m->win[J].bpp), &(m->win[J].lsz), &(m->win[J].edn));
	m->win[M].zoom = 0.5;
	m->win[M].ctr[0] = -0.65;
	m->win[M].ctr[1] = 0;
	m->win[J].zoom = 0.2;
	m->win[J].ctr[0] = 0;
	m->win[J].ctr[1] = 0;
	m->win[J].cur[0] = -0.8;
	m->win[J].cur[1] = 0.2;
	m->win[J].cur[2] = 0;
	return (0);
}
