/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:07:45 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/15 15:11:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char *argv[])
{
	t_mlx	m;

	if (ft_init(argc, argv, &m))
		return (EXIT_FAILURE);
	if ((m.mlx = mlx_init()) == NULL || ft_win_set(&m))
		return (EXIT_FAILURE);
	mlx_loop(m.mlx);
	return (EXIT_SUCCESS);
}
