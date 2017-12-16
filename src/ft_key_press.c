/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:00:12 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 17:12:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_press(int key, t_win *w)
{
	printf("key: %d\n", key);

	t_mlx	*m;

	if (key == 53 || key == 65307)//esc
	{
		m = (t_mlx*)w->mlx;
		mlx_destroy_image(m->mlx, w->img);
		mlx_destroy_window(m->mlx, w->ptr);
		w->ptr = NULL;
		if (m->win[0].ptr || m->win[1].ptr || m->win[2].ptr)
			return (0);
		exit(EXIT_SUCCESS);
	}
	if (key == 49) //space
		w->set[1] = (w->set[1] + 1) % 2;
	return (0);
}
