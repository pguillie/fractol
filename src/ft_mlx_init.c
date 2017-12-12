/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:34 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 14:32:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mlx_init(t_mlx m, int ac, char **av)
{
	(void)ac;
	(void)av;
	//parse av
	m.img.dim[0] = 1000;
	m.img.dim[1] = 1000;
	if ((m.mlx = mlx_init()) == NULL)
		return (-1);
	if ((m.win = mlx_new_window(m.mlx, m.dim[0], m.dim[1], "window")) == NULL)
		return (-1);
	if ((m.img.ptr = mlx_new_image(m.mlx, m.img.dim[0], m.img.dim[1])) == NULL)
		return (-1);
	m.img.zoom = 1;
	ft_memset(m.img.center, 0, sizeof(double) * 2);
	return (0);
}
