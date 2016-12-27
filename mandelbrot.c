/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:45:01 by behamon           #+#    #+#             */
/*   Updated: 2016/12/19 17:45:02 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		calc_mandelbrot(t_env *e)
{
	int		i;
	double	tmp;

	i = 0;
	e->z.re = 0;
	e->z.im = 0;
	while (i < e->itmax && (e->z.re * e->z.re + e->z.im * e->z.im) < 4)
	{
		tmp = e->z.re;
		e->z.re = (e->z.re * e->z.re) - (e->z.im * e->z.im) + e->c.re;
		e->z.im = 2 * tmp * e->z.im + e->c.im;
		i++;
	}
	return (i);
}

void			mandelbrot_init(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 510;
	e->itmax = 40;
	e->col.r = 1;
	e->col.g = 1;
	e->col.b = 1;
}

void			mandelbrot(t_env *e)
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
			e->c.re = x / e->zoom + e->x1;
			e->c.im = y / e->zoom + e->y1;
			c = get_color(calc_mandelbrot(e), e);
			put_pixel_to_image(x, y, e, c);
		}
	}
}
