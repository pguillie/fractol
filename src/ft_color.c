#include "fractol.h"



void	ft_color(t_win w, int *p, int *i)
{
  int	color;

  color = ((i[1] * 0xFF / i[0]) << 16) + 0xFF - i[1] * 0xFF / i[0];
  ft_memcpy(w.str + p[1] * w.lsz + p[0] * w.bpp / 8, (char*)&color, 4);
}
