/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:34 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 18:05:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mlx_init(t_mlx *m, int ac, char **av)
{
	(void)ac;
	(void)av;
	//parse av
	m->img.width = 1000;
	m->img.height = 1000;
	if ((m->mlx = mlx_init()) == NULL)
		return (-1);
	if ((m->win = mlx_new_window(m->mlx, m->img.width, m->img.height, "window")) == NULL)
		return (-1);
	if ((m->img.ptr = mlx_new_image(m->mlx, m->img.width, m->img.height)) == NULL)
		return (-1);
	m->img.addr = mlx_get_data_addr(m->img.ptr, &(m->img.bpp), &(m->img.lsize), &(m->img.endian));
	m->img.zoom = 0.5;
	m->img.center[0] = -0.65;
	m->img.center[1] = 0;
	return (0);
}
