/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:24:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 17:19:36 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# define SIZE_DFL 1000
# define SIZE_MIN 100
# define SIZE_MAXX 2560
# define SIZE_MAXY 1440

# define WIN_MAX 4;

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

# include "mlx.h"
# include "struct.h"

int		ft_init(int ac, char **av, t_mlx *m);
int		ft_win_set(t_mlx *m);

void	ft_fractal(t_win w);
int		ft_sequence1(double *c, double *z, int i);
int		ft_sequence2(double *c, double *z, int i);
int		ft_sequence3(double *c, double *z, int i);
void	ft_init1(double *c, double *z, int *p, t_win w);
void	ft_init2(double *c, double *z, int *p, t_win w);
void	ft_reset_m1(t_win *w);
void	ft_reset_m2(t_win *w);
void	ft_reset_j(t_win *w);

int		ft_key_press(int key, t_win *w);
int		ft_button_press(int button, int x, int y, t_win *w);
int		ft_pointer_motion(int x, int y, t_win *w);

void	ft_color(t_win w, int *p, int *i);

/*
**	LIBFT
*/

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);

#include <stdio.h>

#endif
