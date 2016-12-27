/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:41:00 by behamon           #+#    #+#             */
/*   Updated: 2016/12/20 21:41:02 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		calc_burningship(t_env *e)
{
	int		i;
	double	tmp;

	i = 0;
	e->z.re = 0;
	e->z.im = 0;
	while (i < e->itmax && (e->z.re * e->z.re + e->z.im * e->z.im) < 4)
	{
		tmp = e->z.re;
		e->z.re = ft_abs(e->z.re * e->z.re) - e->z.im * e->z.im + e->c.re;
		e->z.im = 2 * ft_abs(e->z.im) * ft_abs(tmp) + e->c.im;
		i++;
	}
	return (i);
}

void			burningship_init(t_env *e)
{
	e->x1 = -3;
	e->x2 = 2;
	e->y1 = -3;
	e->y2 = 2;
	e->zoom = 300;
	e->itmax = 20;
	e->col.r = 1;
	e->col.g = 1;
	e->col.b = 1;
}

void			burningship(t_env *e)
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
			c = get_color(calc_burningship(e), e);
			put_pixel_to_image(x, y, e, c);
		}
	}
}
