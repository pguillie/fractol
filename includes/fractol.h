/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:24:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/14 18:03:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "struct.h"

# define SIZE_DFL 1000
# define SIZE_MIN 100
# define SIZE_X 2560
# define SIZE_Y 1440

# define J 0
# define M 1
# define A 2

# define BUTTON1 1
# define BUTTON2 2
# define BUTTON3 3
# define BUTTON4 4
# define BUTTON5 5

# define KEY_UP 126
# define KEY_DO 125
# define KEY_RI 124
# define KEY_LE 123

# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define POINTERMOTIONMASK (1L<<6)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6

int		ft_arg(int ac, char **av, t_mlx *m);
int		ft_init_j(t_mlx *m);
int		ft_init_m(t_mlx *m);

/*
**	FRACTALES
*/

void	ft_mandelbrot(t_win w);
void	ft_julia(t_win w);
void	ft_mandelcube(t_win w);

/*
**	MLX EVENTS
*/

int		ft_zoom(t_win *w, int key, int x, int y);
int		ft_move(t_win *w, int key, int x, int y);
int		ft_pointer(t_win *w, int key, int x, int y);

int		ft_mouse_m(int key, int x, int y, t_mlx *m);
int		ft_mouse_j(int key, int x, int y, t_mlx *m);

int     ft_pointer_j(int x, int y, t_mlx *m);
int     ft_pointer_m(int x, int y, t_mlx *m);

int		ft_keyboard_m(int key, t_mlx *m);
int		ft_keyboard_j(int key, t_mlx *m);

/*
**	LIBFT
*/

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t len);

#endif
