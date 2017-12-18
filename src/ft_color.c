/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:56:15 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 12:07:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	test(int i, int m, int c1, int c2)
{
	unsigned char	a[3];
	unsigned char	b[3];

	a[0] = (c1 << 8) >> 24;
	a[1] = (c1 << 16) >> 24;
	a[2] = (c1 << 24) >> 24;
	b[0] = (c2 << 8) >> 24;
	b[1] = (c2 << 16) >> 24;
	b[2] = (c2 << 24) >> 24;
	return (((i * a[0] / m) << 16)
			+ ((i * a[1] / m) << 8)
			+ (i * a[2] / m)
			+ ((b[0] - i * b[0] / m) << 16)
			+ ((b[1] - i * b[1] / m) << 8)
			+ (b[2] - i * b[2] / m));
}

void		ft_color(t_win w, int *p, int *i)
{
	int	color;

	if (i[0] == i[1])
		color = 0;
	else if (i[0] % 100 > 75)
		color = test(i[0] % 100 - 75, 25, w.col[0], w.col[1]);
	else if (i[0] % 100 > 50)
		color = test(i[0] % 100 - 50, 25, w.col[1], w.col[2]);
	else if (i[0] % 100 > 25)
		color = test(i[0] % 100 - 25, 25, w.col[2], w.col[3]);
	else
		color = test(i[0] % 100, 25, w.col[3], w.col[0]);
	ft_memcpy(w.str + p[1] * w.lsz + p[0] * w.bpp / 8, (char*)&color, 3);
}
