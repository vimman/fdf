/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:07 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_point a, t_point b, t_env *e)
{
	t_bres br;

	br.dx = abs(b.x - a.x);
	br.sx = a.x < b.x ? 1 : -1;
	br.dy = abs(b.y - a.y);
	br.sy = a.y < b.y ? 1 : -1;
	br.err = (br.dx > br.dy ? br.dx : -br.dy) / 2;
	br.e2 = 0;
	while (1)
	{
		put_pixel(&a, e);
		if (a.x == b.x && a.y == b.y)
			break ;
		br.e2 = br.err;
		if (br.e2 > -br.dx)
		{
			br.err -= br.dy;
			a.x += br.sx;
		}
		if (br.e2 < br.dy)
		{
			br.err += br.dx;
			a.y += br.sy;
		}
	}
}
