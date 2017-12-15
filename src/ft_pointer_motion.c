/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_motion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:14:47 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 17:18:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_pointer_motion(int x, int y, t_win *w)
{
	t_mlx	*m;

	if (w->set[1] == 0)
		return (0);
	m = (t_mlx*)w->mlx;
	w->cur[0] = x / (w->wdt / 2.0) - 1;
	w->cur[1] = y / (w->hgt / 2.0) - 1;
	ft_fractal(*w);
	mlx_put_image_to_window(m->mlx, w->ptr, w->img, 0, 0);
	return (0);
}
