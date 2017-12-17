/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:39:38 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/16 17:00:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* void		ft_fractal(t_win w) */
/* { */
/* 	double	c[2]; */
/* 	double	z[2]; */
/* 	int		p[2]; */
/* 	int		i[2]; */

/* 	i[1] = w.i + w.zoom; */
/* 	p[0] = 0; */
/* 	while (p[0] < w.wdt) */
/* 	{ */
/* 		p[1] = 0; */
/* 		while (p[1] < w.hgt) */
/* 		{ */
/* 			w.init_seq(c, z, p, w); */
/* 			i[0] = w.sequence(c, z, i[1]); */
/* 			ft_color(w, p, i); */
/* 			p[1]++; */
/* 		} */
/* 		p[0]++; */
/* 	} */
/* } */

static void	*ft_fractal_thread(void *arg)
{
  t_thread	*a;
  double	c[2];
  double	z[2];
  int		p[2];
  int		i[2];

  a = (t_thread*)arg;
  dprintf(a->beg / THREAD_NB + 5, " == THREAD ==\n" );
  i[1] = a->w.i + a->w.zoom;
  p[1] = a->beg;
  while (p[1] < a->end)
    {
      p[0] = 0;
      while (p[0] < a->w.wdt)
	{
	  dprintf(a->beg / THREAD_NB + 5, "(%3d,%3d)", p[0], p[1]);
	  a->w.init_seq(c, z, p, a->w);
	  i[0] = a->w.sequence(c, z, i[1]);
	  ft_color(a->w, p, i);
	  p[0]++;
	}
      p[1]++;
    }
  dprintf(a->beg / THREAD_NB + 5, "\n== ==\n");
  pthread_exit(NULL);
  return (NULL);
}

static void	ft_pthread_del(pthread_t *t)
{
  int	i;
  
  i = 0;
  while (i < THREAD_NB)
    pthread_cancel(t[i++]);
  write(2, "Error: thread could not be initialized.\n", 40);
}

void		ft_fractal(t_win w)
{
  pthread_t	t[THREAD_NB];
  t_thread	arg;
  int		i;

  i = 0;
  ft_memset(t, 0, sizeof(pthread_t) * THREAD_NB);
  while (i < THREAD_NB)
    {
      arg.w = w;
      arg.beg = i * w.hgt / THREAD_NB;
      arg.end = (i + 1) * w.hgt / THREAD_NB;
      if (pthread_create(t + i++, NULL, ft_fractal_thread, &arg))
	ft_pthread_del(t);
    }
  printf("foo\n");
  i = 0;
  while (i < THREAD_NB)
    {
      pthread_join(t[i++], NULL);
    }
}
