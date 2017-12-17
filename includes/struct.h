/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:11:41 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/16 16:44:14 by pguillie         ###   ########.fr       */
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
  int		i;
  int		set[2];
	int		col[5];
	void	(*init_seq)(double *c, double *z, int *p, struct s_win w);
	int		(*sequence)(double *c, double *z, int i);
	void	(*reset)(struct s_win *w);
}				t_win;

typedef struct	s_thread
{
  t_win	w;
  int	beg;
  int	end;
}		t_thread;

typedef struct	s_mlx
{
	void	*mlx;
	t_win	win[3];
}				t_mlx;

#endif
