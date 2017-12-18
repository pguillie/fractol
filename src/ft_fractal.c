/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:39:38 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/18 21:22:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*ft_fractal_thread(void *arg)
{
	t_thread	*t;
	double		c[2];
	double		z[2];
	int			p[2];
	int			i[2];

	t = (t_thread*)arg;
	i[1] = t->w.i + t->w.zoom;
	p[1] = t->beg;
	while (p[1] < t->end)
	{
		p[0] = 0;
		while (p[0] < t->w.wdt)
		{
			t->w.init_seq(c, z, p, t->w);
			i[0] = t->w.sequence(c, z, i[1]);
			ft_color(t->w, p, i);
			p[0]++;
		}
		p[1]++;
	}
	pthread_exit(NULL);
	return (NULL);
}

static void	ft_pthread_del(t_thread *t)
{
	int	i;

	i = 0;
	while (i < THREAD_NB)
		pthread_cancel(t[i++].id);
	write(2, "Error: thread could not be initialized.\n", 40);
}

void		ft_fractal(t_win w)
{
	t_thread	t[THREAD_NB];
	int			i;

	i = 0;
	ft_memset(t, 0, sizeof(pthread_t) * THREAD_NB);
	while (i < THREAD_NB)
	{
		t[i].w = w;
		t[i].beg = i * w.hgt / THREAD_NB;
		t[i].end = (i + 1) * w.hgt / THREAD_NB;
		if (pthread_create(&t[i].id, NULL, ft_fractal_thread, &t[i]))
			ft_pthread_del(t);
		i++;
	}
	i = 0;
	while (i < THREAD_NB)
		pthread_join(t[i++].id, NULL);
}
