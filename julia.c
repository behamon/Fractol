/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:45:10 by behamon           #+#    #+#             */
/*   Updated: 2016/12/19 17:45:11 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		calc_julia(t_env *e, int x, int y)
{
	int		i;
	double	tmp;

	i = 0;
	e->z.re = x / e->zoom + e->x1;
	e->z.im = y / e->zoom + e->y1;
	while (i < e->itmax && (e->z.re * e->z.re + e->z.im * e->z.im) < 4)
	{
		tmp = e->z.re;
		e->z.re = (e->z.re * e->z.re) - (e->z.im * e->z.im) + e->c.re;
		e->z.im = 2 * tmp * e->z.im + e->c.im;
		i++;
	}
	return (i);
}

void			julia_init(t_env *e)
{
	e->x1 = -2;
	e->x2 = 2.5;
	e->y1 = -1.5;
	e->y2 = 3;
	e->zoom = 350;
	e->itmax = 50;
	e->col.r = 1;
	e->col.g = 1;
	e->col.b = 1;
}

void			julia(t_env *e)
{
	int		x;
	int		y;
	int		c;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			e->c.re = -1 + (e->mouse_x * 0.002);
			e->c.im = -1.2 + (e->mouse_y * 0.002);
			c = get_color(calc_julia(e, x, y), e);
			put_pixel_to_image(x, y, e, c);
		}
	}
}
