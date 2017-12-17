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

	m = (t_mlx*)(w->mlx);
	if (key == KEY_ESC)
	{
		mlx_destroy_image(m->mlx, w->img);
		mlx_destroy_window(m->mlx, w->ptr);
		w->ptr = NULL;
		if (m->win[0].ptr || m->win[1].ptr || m->win[2].ptr)
			return (0);
		exit(EXIT_SUCCESS);
	}
	if (key == KEY_SPC)
	  {
	    w->set[1] = (w->set[1] + 1) % 2;
	    return (0);
	  }
	if (key == KEY_RAZ)
	  w->reset(w);
	else if (key == KEY_PLUS)
	  w->i += 10;
	else if (key == KEY_MINUS && w->i > 10)
	  w->i -= 10;
	ft_fractal(*w);
	mlx_put_image_to_window(m->mlx, w->ptr, w->img, 0, 0);
	return (0);
}
