/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 12:24:32 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/16 16:55:33 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_usage(char *arg)
{
	if (arg)
	{
		write(2, "fractol: bad argument: ", 23);
		write(2, arg, ft_strlen(arg));
		write(2, "\n", 1);
	}
	write(2, "usage: fractol [widht [height]] ID ...\n", 39);
	write(2, "\tID: J1 J2 J3 M1 M2 M3\n", 23);
	return (-1);
}

static int	ft_size(char **av, int i, int *s)
{
	int		j;
	int		n;

	n = 0;
	j = 0;
	if (s[0] && s[1])
		return (-i);
	while (av[i][j] >= '0' && av[i][j] <= '9')
		n = n * 10 + av[i][j++] - '0';
	if (av[i][j] || n == 0)
		return (-i);
	if (s[0] == 0)
		s[0] = n;
	else
		s[1] = n;
	return (i + 1);	
}

static void	ft_name_size(int *s, t_win *w)
{
	if (s[0] == 0)
		s[0] = SIZE_DFL;
	if (s[1] == 0)
		s[1] = s[0];
	if (s[0] < SIZE_MIN)
		s[0] = SIZE_MIN;
	if (s[0] > SIZE_MAXX)
		s[0] = SIZE_MAXX;
	if (s[1] < SIZE_MIN)
		s[1] = SIZE_MIN;
	if (s[1] > SIZE_MAXY)
		s[1] = SIZE_MAXY;
	w->wdt = s[0];
	w->hgt = s[1];
	ft_memset(s, 0, sizeof(int) * 2);
}

static int	ft_name(char **av, int i, int *s, t_win *w)
{
	if (ft_strlen(av[i]) != 2 && ft_strcmp(av[i], "mandelbrot")
		&& ft_strcmp(av[i], "julia"))
		return (-i);
	if (av[i][0] == 'M' || av[i][0] == 'm')
		w->init_seq = &ft_init1;
	else if (av[i][0] == 'J' || av[i][0] == 'j')
		w->init_seq = ft_init2;
	else
		return (-i);
	if (av[i][1] == '1' || ft_strlen(av[i]) > 2)
		w->sequence = ft_sequence1;
	else if (av[i][1] == '2')
		w->sequence = ft_sequence2;
	else if (av[i][1] == '3')
		w->sequence = ft_sequence3;
	else
		return (-i);
	ft_name_size(s, w);
	w->set[0] = 1;
	return (i + 1);
}

int			ft_init(int ac, char **av, t_mlx *m)
{
	int		i;
	int		w;
	int		s[2];

	w = 0;
	i = 1;
	ft_memset(s, 0, sizeof(int) * 2);
	ft_memset(m, 0, sizeof(*m));
	while (i < ac && w < 3)
	{
		if (av[i][0] >= '0' && av[i][0] <= '9')
			i = ft_size(av, i, s);
		else
			i = ft_name(av, i, s, &m->win[w++]);
		if (i < 0)
			return (ft_usage(av[-i]));
	}
	if (w < 1 || i < ac)
	{
		write(2, "Please select between 1 and 3 fractals.\n", 40);
		return (ft_usage(NULL));
	}
	return (0);
}
