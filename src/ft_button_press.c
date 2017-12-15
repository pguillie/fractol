/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:46:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 11:05:57 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_button_press(int button, int x, int y, t_win *w)
{
	if (button == BUTTON5)
	{
		w->ctr[0] = (w->ctr[0] + x / (w->wdt * w->zoom)
					 - 0.5 / w->zoom + w->ctr[0]) / 2;
		w->ctr[1] = (w->ctr[1] + y / (w->hgt * w->zoom)
					 - 0.5 / w->zoom + w->ctr[1]) / 2;
		w->zoom *= 2;
	}
	else if (button == BUTTON4 && w->zoom > 0.001)
	{
		w->ctr[0] = 2 * w->ctr[0] - x / (w->wdt * w->zoom)
			+ 0.5 / w->zoom - w->ctr[0];
		w->ctr[1] = 2 * w->ctr[1] - y / (w->hgt * w->zoom)
			+ 0.5 / w->zoom - w->ctr[1];
		w->zoom /= 2;
	}
	else if (button == BUTTON2)
	{
		w->ctr[0] = x / (w->wdt * w->zoom) - 0.5 / w->zoom + w->ctr[0];
		w->ctr[1] = y / (w->hgt * w->zoom) - 0.5 / w->zoom + w->ctr[1];
	}
	else
		return (1);
	ft_fractal(*w);
	mlx_put_image_to_window(w->mlx, w->ptr, w->img, 0, 0);
	return (0);
}
