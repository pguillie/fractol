/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:07:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/19 10:05:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_color_set1(t_win *w)
{
	w->col[1] = (0xFF << 16) + (0xFF << 8) + 0xFF;
	w->col[2] = 0xFF;
	w->col[3] = 0xFF << 16;
	w->col[4] = (0xFF << 16) + (0xBF << 8);
}

static void	ft_color_set2(t_win *w)
{
	w->col[1] = (0x23 << 16) + (0x57 << 8) + 0x64;
	w->col[2] = (0x42 << 16) + (0xD8 << 8) + 0xBF;
	w->col[3] = (0x30 << 16) + (0x89 << 8) + 0xB3;
	w->col[4] = (0x3C << 16) + (0x50 << 8) + 0xB3;
}

static void	ft_color_set3(t_win *w)
{
	w->col[1] = (0xC7 << 16) + (0x00 << 8) + 0x39;
	w->col[2] = (0x90 << 16) + (0x0C << 8) + 0x3F;
	w->col[3] = (0xFF << 16) + (0x57 << 8) + 0x33;
	w->col[4] = (0xFF << 16) + (0xC3 << 8) + 0x00;
}

static void	ft_color_set4(t_win *w)
{
	w->col[1] = (0xFF << 16) + (0xFF << 8) + 0xFF;
	w->col[2] = (0xBB << 16) + (0xBB << 8) + 0xBB;
	w->col[3] = (0x55 << 16) + (0x55 << 8) + 0x55;
	w->col[4] = (0x11 << 16) + (0x11 << 8) + 0x11;
}

void		ft_color_set(t_win *w)
{
	if (w->col[0] == 0)
		ft_color_set1(w);
	else if (w->col[0] == 1)
		ft_color_set2(w);
	else if (w->col[0] == 2)
		ft_color_set3(w);
	else if (w->col[0] == 3)
		ft_color_set4(w);
	w->col[0] = (w->col[0] + 1) % 4;
}
