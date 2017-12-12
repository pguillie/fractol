/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:11:41 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 16:36:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		lsize;
	int		endian;
	double	zoom;
	double	center[2];
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}				t_mlx;

#endif
