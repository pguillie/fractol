/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:11:41 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 16:32:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_win
{
	void	*mlx;
	void	*ptr;
	void	*img;
	char	*str;
	int		wdt;
	int		hgt;
	int		bpp;
	int		lsz;
	int		edn;
	double	zoom;
	double	ctr[2];
	double	cur[2];
	int		set[2];
	void	(*init_seq)(double *c, double *z, int *p, struct s_win w);
	int		(*sequence)(double *c, double *z, int i);
	void	(*reset)(struct s_win *w);
}				t_win;

typedef struct	s_mlx
{
	void	*mlx;
	t_win	win[3];
}				t_mlx;

#endif
