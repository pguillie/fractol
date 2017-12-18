/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:07:17 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 22:49:47 by pguillie         ###   ########.fr       */
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
	w->col[1] = 0xFF << 8;
	w->col[2] = (0xAA << 16) + 0xAA;
	w->col[3] = 0xAA;
	w->col[4] = 0xFF;
}

static void	ft_color_set3(t_win *w)
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
	w->col[0] = (w->col[0] + 1) % 3;
}
