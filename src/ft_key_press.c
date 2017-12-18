/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:00:12 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 22:32:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_key_mv(int key, t_win *w, t_mlx *m)
{
	if (key == KEY_UP)
		w->mv[1] += 10;
	else if (key == KEY_DO)
		w->mv[1] -= 10;
	else if (key == KEY_RI)
		w->mv[0] -= 10;
	else if (key == KEY_LE)
		w->mv[0] += 10;
	mlx_clear_window(m->mlx, w->ptr);
	mlx_put_image_to_window(m->mlx, w->ptr, w->img, w->mv[0], w->mv[1]);
	return (0);
}

int			ft_key_press(int key, t_win *w)
{
	t_mlx	*m;

	m = (t_mlx*)(w->mlx);
	if (key == KEY_ESC)
		return (ft_close(w, m));
	if (key == KEY_SPC)
		w->set[1] = (w->set[1] + 1) % 2;
	if (key == KEY_RAZ)
		w->reset(w);
	else if (key == KEY_PLUS)
		w->i += 10;
	else if (key == KEY_MINUS && w->i > 10)
		w->i -= 10;
	else if (key == KEY_COL)
		ft_color_set(w);
	else if (key == KEY_UP || key == KEY_DO || key == KEY_RI || key == KEY_LE)
		return (ft_key_mv(key, w, m));
	else
		return (0);
	ft_fractal(*w);
	mlx_put_image_to_window(m->mlx, w->ptr, w->img, 0, 0);
	return (0);
}
