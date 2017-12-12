/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 12:32:35 by pguillie          #+#    #+#             */
/*   Updated: 2017/12/12 15:09:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memset(void *p, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char*)p;
	while (len-- > 0)
		str[len] = (unsigned char)c;
	return (p);
}
