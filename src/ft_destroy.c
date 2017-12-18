/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:26:19 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 22:31:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(t_win *w, t_mlx *m)
{
	mlx_destroy_image(m->mlx, w->img);
	mlx_destroy_window(m->mlx, w->ptr);
	w->ptr = NULL;
	if (!(m->win[0].ptr || m->win[1].ptr || m->win[2].ptr))
		exit(EXIT_SUCCESS);
	return (0);
}

int		ft_event_close(t_win *w)
{
	return (ft_close(w, (t_mlx*)w->mlx));
}
