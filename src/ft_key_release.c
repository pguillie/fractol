/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:21:07 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 21:15:11 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_release(int key, t_win *w)
{
	t_mlx	*m;

	if (key == KEY_UP || key == KEY_DO || key == KEY_RI || key == KEY_LE)
	{
		m = (t_mlx*)(w->mlx);
		w->ctr[0] -= w->mv[0] / (w->zoom * w->min);
		w->ctr[1] -= w->mv[1] / (w->zoom * w->min);
		w->mv[0] = 0;
		w->mv[1] = 0;
		ft_fractal(*w);
		mlx_put_image_to_window(m->mlx, w->ptr, w->img, 0, 0);
	}
	return (0);
}
