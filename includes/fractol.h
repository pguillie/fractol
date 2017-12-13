/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:24:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 15:08:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "struct.h"

# define M 0
# define J 1

# define MOUSE_L 1
# define MOUSE_R 2
# define MOUSE_D 4
# define MOUSE_U 5

# define KEYPRESS 2
# define KEYPRESSMASK (1L << 0)

# define MOTIONNOTIFY 6
# define POINTERMASK (1L << 6)

/*
**	FRACTALES
*/

void	ft_mandelbrot(t_win w);
void	ft_julia(t_win w);

/*
**	MLX
*/

int		ft_mlx_init(t_mlx *m, int ac, char **av);

int		ft_mouse_m(int key, int x, int y, t_mlx *m);
int		ft_mouse_j(int key, int x, int y, t_mlx *m);
int     ft_mouse_over(int x, int y, t_mlx *m);

int		ft_keyboard_m(int key, t_mlx *m);
int		ft_keyboard_j(int key, t_mlx *m);

/*
**	LIBFT
*/

void	*ft_memset(void *p, int c, size_t len);

#endif
