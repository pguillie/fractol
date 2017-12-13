/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:26:16 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 18:25:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_usage(void)
{
	write(2, "usage: fractol ", 15);
	write(2, "mandelbrot [width] [height] ", 29);
	write(2, "julia [width] [height]\n", 24);
	return (-1);
}

static int	ft_bad_arg(char *arg)
{
	write(2, "fractol: ", 9);
	write(2, arg, ft_strlen(arg));
	write(2, ": invalid argument.\n", 20);
	return (ft_usage());
}

static int	ft_arg_size(char *str)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] >= '0' && str[i] <= '9')
		size = size * 10 + str[i++] - '0';
	if (str[i])
		return (0);
	return (size);
}

static int	ft_arg_frac(int ac, char **av, int i, t_win *w)
{
	int		size;

	size = (i == ac ? 0 : ft_arg_size(av[i]));
	if (size)
	{
		w->wdt = size;
		i += 1;
		size = (i == ac ? 0 : ft_arg_size(av[i]));
	}
	else
		w->wdt = 1000;
	if (size)
	{
		w->hgt = size;
		i += 1;
	}
	else
		w->hgt = w->wdt;
	return (i);
}

int			ft_arg(int ac, char **av, t_mlx *m)
{
	int		i;

	ft_memset(m, 0, sizeof(t_mlx));
	if ((i = 1) == ac)
		return (ft_usage());
	while (i > 0 && i < ac)
	{
		if (ft_strcmp(av[i], "mandelbrot") == 0)
			i = ft_arg_frac(ac, av, i + 1, &(m->win[M]));
		else if (ft_strcmp(av[i], "julia") == 0)
			i = ft_arg_frac(ac, av, i + 1, &(m->win[J]));
		else
			return (ft_bad_arg(av[i]));
	}
	return (0);
}
