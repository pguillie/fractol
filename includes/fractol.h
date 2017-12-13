/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:24:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/13 18:02:33 by pguillie         ###   ########.fr       */
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

int		ft_arg(int ac, char **av, t_mlx *m);

/*
**	FRACTALES
*/

void	ft_mandelbrot(t_win w);
void	ft_julia(t_win w);

/*
**	MLX
*/

int		ft_mlx_init(t_mlx *m);

int		ft_mouse_m(int key, int x, int y, t_mlx *m);
int		ft_mouse_j(int key, int x, int y, t_mlx *m);
int     ft_mouse_over(int x, int y, t_mlx *m);

int		ft_keyboard_m(int key, t_mlx *m);
int		ft_keyboard_j(int key, t_mlx *m);

/*
**	LIBFT
*/

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t len);

#endif
