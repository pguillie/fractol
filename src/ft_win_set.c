/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:14:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 17:19:09 by pguillie         ###   ########.fr       */
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
		w->reset = ft_reset_m1;
		return ("Mandelbrot(2)");
	}
	if (w->sequence == ft_sequence3)
	{
		w->reset = ft_reset_m2;
		return ("Mandelbrot(3)");
	}
	return (NULL);
}

static char	*ft_win_set_j(t_win *w)
{
	w->reset = ft_reset_j;
	if (w->sequence == ft_sequence1)
	{
		w->cur[0] = 0.8;
		w->cur[1] = 0.02;
		return ("Julia");
	}
	if (w->sequence == ft_sequence2)
	{
		w->cur[0] = 0.2;
		w->cur[1] = 0.5;
		return ("Julia(2)");
	}
	if (w->sequence == ft_sequence3)
	{
		w->cur[0] = 0.01;
		w->cur[1] = 0.21;
		return ("Julia(3)");
	}
	return (NULL);
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
		m->win[i].ptr = mlx_new_window(m->mlx, m->win[i].wdt,
									   m->win[i].hgt, name);
		m->win[i].img = mlx_new_image(m->mlx, m->win[i].wdt, m->win[i].hgt);
		m->win[i].str = mlx_get_data_addr(m->win[i].img, &m->win[i].bpp,
										  &m->win[i].lsz, &m->win[i].edn);
		mlx_hook(m->win[i].ptr, KEYPRESS, KEYPRESSMASK, ft_key_press, &m->win[i]);
		mlx_hook(m->win[i].ptr, BUTTONPRESS, BUTTONPRESSMASK,
				 ft_button_press, &m->win[i]);
		mlx_hook(m->win[i].ptr, MOTIONNOTIFY, POINTERMOTIONMASK,
				 ft_pointer_motion, &m->win[i]);
		m->win[i].reset(&m->win[i]);
		ft_fractal(m->win[i]);
		mlx_put_image_to_window(m->mlx, m->win[i].ptr, m->win[i].img, 0, 0);
		i++;
	}
	return (0);
}
