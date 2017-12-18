/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:46:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 21:12:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_button_press(int button, int x, int y, t_win *w)
{
	t_mlx	*m;
  
	m = (t_mlx*)(w->mlx);
	if (button == BUTTON4)
	{
		w->ctr[0] = (w->ctr[0] + x / (w->min * w->zoom)
					 - (double)w->wdt / (double)w->min / 2 / w->zoom
					 + w->ctr[0]) / 2;
		w->ctr[1] = (w->ctr[1] + y / (w->min * w->zoom)
					 - (double)w->hgt / (double)w->min / 2 / w->zoom
					 + w->ctr[1]) / 2;
		w->zoom *= 2;
	}
	else if (button == BUTTON5 && w->zoom > 0.001)
	{
		w->ctr[0] = 2 * w->ctr[0] - x / (w->min * w->zoom)
			+ (double)w->wdt / (double)w->min / 2 / w->zoom 
			- w->ctr[0];
		w->ctr[1] = 2 * w->ctr[1] - y / (w->min * w->zoom)
			+ (double)w->hgt / (double)w->min / 2 / w->zoom
			- w->ctr[1];
		w->zoom /= 2;
	}
	else if (button == BUTTON2)
	{
		w->ctr[0] = x / (w->min * w->zoom)
			- (double)w->wdt / (double)w->min / 2 / w->zoom + w->ctr[0];
		w->ctr[1] = y / (w->min * w->zoom)
			- (double)w->hgt / (double)w->min / 2 / w->zoom + w->ctr[1];
	}
	else
		return (1);
	ft_fractal(*w);
	mlx_put_image_to_window(m->mlx, w->ptr, w->img, 0, 0);
	return (0);
}
