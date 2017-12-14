/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:57:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 17:58:48 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_zoom(t_win *w, int mode, int x, int y)
{
	if (mode == BUTTON5)
	{
		w->ctr[0] = (w->ctr[0] + x / (w->wdt * w->zoom) - 0.5 / w->zoom + w->ctr[0])
			/ 2;
		w->ctr[1] = (w->ctr[1] + y / (w->hgt * w->zoom) - 0.5 / w->zoom + w->ctr[1])
			/ 2;
		w->zoom *= 2;
	}
	else if (mode == BUTTON4 && w->zoom > 0.001)
	{
		w->ctr[0] = 2 * w->ctr[0] - x / (w->wdt * w->zoom)
			+ 0.5 / w->zoom - w->ctr[0];
		w->ctr[1] = 2 * w->ctr[1] - y / (w->hgt * w->zoom)
			+ 0.5 / w->zoom - w->ctr[1];
		w->zoom /= 2;
	}
	else
		return (1);
	return (0);
}

int		ft_move(t_win *w, int mode, int x, int y)
{
	if (mode == BUTTON1)
	{
		w->ctr[0] = x / (w->wdt * w->zoom) - 0.5 / w->zoom + w->ctr[0];
		w->ctr[1] = y / (w->hgt * w->zoom) - 0.5 / w->zoom + w->ctr[1];
	}
	else if (mode == KEY_UP)
		w->ctr[1] += 0.1 / w->zoom;
	else if (mode == KEY_DO)
		w->ctr[1] -= 0.1 / w->zoom;
	else if (mode == KEY_RI)
		w->ctr[0] += 0.1 / w->zoom;
	else if (mode == KEY_LE)
		w->ctr[0] -= 0.1 / w->zoom;
	else
		return (1);
	return (0);
}

int		ft_pointer(t_win *w, int key, int x, int y)
{
	if (key == BUTTON2)
		w->cur[2] = (int)(w->cur[2] + 1) % 2;
	else if (w->cur[2])
	{
		w->cur[0] = x / (w->wdt / 2.0) - 1;
		w->cur[1] = y / (w->hgt / 2.0) - 1;
	}
	return (0);
}
