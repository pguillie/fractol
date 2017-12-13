/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:53:47 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 14:30:33 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_keyboard_m(int key, t_mlx *m)
{
	if (key == 53)
	{
		mlx_destroy_image(m->mlx, m->win[M].img);
		mlx_destroy_window(m->mlx, m->win[M].ptr);
		m->win[M].ptr = NULL;
		if (m->win[J].ptr == NULL)
			exit(EXIT_SUCCESS);
		return (0);
	}
	return (0);
}

int		ft_keyboard_j(int key, t_mlx *m)
{
	if (key == 53)
	{
		mlx_destroy_image(m->mlx, m->win[J].img);
		mlx_destroy_window(m->mlx, m->win[J].ptr);
		m->win[J].ptr = NULL;
		if (m->win[M].ptr == NULL)
			exit(EXIT_SUCCESS);
		return (0);
	}
	return (0);
}
