/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:11:41 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 15:16:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_win
{
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
	double	cur[3];
}				t_win;

typedef struct	s_mlx
{
	void	*mlx;
	t_win	win[2];
}				t_mlx;

#endif
