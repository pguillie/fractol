/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_seq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:28:03 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 21:13:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init1(double *c, double *z, int *p, t_win w)
{
	z[0] = w.cur[0];
	z[1] = w.cur[1];
	c[0] = p[0] / (w.min * w.zoom)
		- (double)w.wdt / (double)w.min / 2 / w.zoom + w.ctr[0];
	c[1] = p[1] / (w.min * w.zoom)
		- (double)w.hgt / (double)w.min / 2 / w.zoom + w.ctr[1];
}

void	ft_init2(double *c, double *z, int *p, t_win w)
{
	z[0] = p[0] / (w.min * w.zoom)
		- (double)w.wdt / (double)w.min / 2 / w.zoom + w.ctr[0];
	z[1] = p[1] / (w.min * w.zoom)
		- (double)w.hgt / (double)w.min / 2 / w.zoom + w.ctr[1];
	c[0] = w.cur[0];
	c[1] = w.cur[1];
}
