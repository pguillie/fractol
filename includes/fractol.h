/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:24:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 18:10:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "struct.h"

# define KEYPRESS 2
# define KEYPRESSMASK (1L << 0)

void	*ft_memset(void *p, int c, size_t len);

int		ft_mlx_init(t_mlx *m, int ac, char **av);
int		ft_mouse_event(int key, int x, int y, t_mlx *m);
void	ft_mandelbrot(t_img i);

#endif
