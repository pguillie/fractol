/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:18:08 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 16:57:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_reset_m1(t_win *w)
{
	w->zoom = 0.3;
	w->ctr[0] = -0.65;
	w->ctr[1] = 0;
	w->cur[0] = 0;
	w->cur[1] = 0;
}

void	ft_reset_m2(t_win *w)
{
	w->zoom = 0.3;
	w->ctr[0] = 0;
	w->ctr[1] = 0;
	w->cur[0] = 0;
	w->cur[1] = 0;
}

void	ft_reset_j(t_win *w)
{
	w->zoom = 0.2;
	w->ctr[0] = 0;
	w->ctr[1] = 0;
}
