/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequences.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 09:48:51 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 14:01:15 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_sequence1(double *c, double *z, int iterations)
{
	double	t;
	int		i;

	i = 0;
	while (i < iterations && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = t;
		i++;
	}
	return (i);
}

int		ft_sequence2(double *c, double *z, int iterations)
{
	double	t[2];
	int		i;

	i = 0;
	while (i < iterations && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t[0] = (z[0] < 0 ? -z[0] : z[0]);
		t[1] = (z[1] < 0 ? -z[1] : z[1]);
		z[0] = t[0] * t[0] - t[1] * t[1] + c[0];
		z[1] = 2 * t[0] * t[1] + c[1];
		i++;
	}
	return (i);
}

int		ft_sequence3(double *c, double *z, int iterations)
{
	double	t;
	int		i;

	i = 0;
	while (i < iterations && z[0] * z[0] + z[1] * z[1] < 4)
	{
		t = z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c[0];
		z[1] = 3 * z[0] * z[0] * z[1] - z[1] * z[1] * z[1] + c[1];
		z[0] = t;
		i++;
	}
	return (i);
}
