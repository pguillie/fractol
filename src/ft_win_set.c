/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:14:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 23:04:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char	*ft_win_set_m(t_win *w)
{
	if (w->sequence == ft_sequence1)
	{
		w->reset = ft_reset_m1;
		return ("Mandelbrot");
	}
	if (w->sequence == ft_sequence2)
	{
		w->reset = ft_reset_m2;
		return ("Mandelbrot(2)");
	}
	if (w->sequence == ft_sequence3)
	{
		w->reset = ft_reset_m3;
		return ("Mandelbrot(3)");
	}
	if (w->sequence == ft_sequence4)
	{
		w->reset = ft_reset_m4;
		return ("Mandelbrot(4)");
	}
	return (NULL);
}

static char	*ft_win_set_j(t_win *w)
{
	w->reset = ft_reset_j;
	w->cur[0] = -0.048;
	w->cur[1] = -0.494;
	if (w->sequence == ft_sequence1)
	{
		w->cur[0] = 0.366;
		w->cur[1] = 0.128;
		return ("Julia");
	}
	if (w->sequence == ft_sequence2)
	{
		w->cur[0] = 0.294;
		w->cur[1] = 0.014;
		return ("Julia(2)");
	}
	if (w->sequence == ft_sequence3)
	{
		w->cur[0] = 0.548;
		w->cur[1] = 0.238;
		return ("Julia(3)");
	}
	if (w->sequence == ft_sequence4)
		return ("Julia(4)");
	return (NULL);
}

static int	ft_win_set_mlx(t_mlx *m, t_win *w, char *name)
{
	if (!(w->ptr = mlx_new_window(m->mlx, w->wdt, w->hgt, name)))
		return (-1);
	if (!(w->img = mlx_new_image(m->mlx, w->wdt, w->hgt)))
		return (-1);
	w->str = mlx_get_data_addr(w->img, &w->bpp, &w->lsz, &w->edn);
	return (0);
}

static void	ft_win_set_hook(t_win *w)
{
	mlx_hook(w->ptr, KEYPRESS, KEYPRESSMASK, ft_key_press, w);
	mlx_hook(w->ptr, KEYRELEASE, KEYRELEASEMASK, ft_key_release, w);
	mlx_hook(w->ptr, BUTTONPRESS, BUTTONPRESSMASK, ft_button_press, w);
	mlx_hook(w->ptr, MOTIONNOTIFY, POINTERMOTIONMASK, ft_pointer_motion, w);
	mlx_hook(w->ptr, DESTROYNOTIFY, KEYRELEASEMASK, ft_event_close, w);
}

int			ft_win_set(t_mlx *m)
{
	char	*name;
	int		i;

	i = 0;
	while (i < 3 && m->win[i].set[0])
	{
		m->win[i].mlx = m;
		if (m->win[i].init_seq == ft_init1)
			name = ft_win_set_m(&m->win[i]);
		else
			name = ft_win_set_j(&m->win[i]);
		if (ft_win_set_mlx(m, &m->win[i], name))
			return (-1);
		ft_win_set_hook(&m->win[i]);
		m->win[i].i = 100;
		m->win[i].reset(&m->win[i]);
		ft_color_set(&m->win[i]);
		ft_fractal(m->win[i]);
		mlx_put_image_to_window(m->mlx, m->win[i].ptr, m->win[i].img, 0, 0);
		i++;
	}
	return (0);
}
