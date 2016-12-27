/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:17:14 by behamon           #+#    #+#             */
/*   Updated: 2016/12/19 17:43:03 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hooks(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 71)
		mlx_clear_window(e->mlx, e->win);
	if (keycode == 49 && e->lock == 0)
		e->lock = 1;
	else if (keycode == 49 && e->lock == 1)
		e->lock = 0;
	if (keycode == 15)
		e->col.r += 1;
	if (keycode == 5)
		e->col.g += 1;
	if (keycode == 11)
		e->col.b += 1;
	if (keycode == 0)
	{
		e->col.r = 1;
		e->col.g = 0;
		e->col.b = 0;
	}
	return (0);
}

int		mouvement_fractol(int keycode, t_env *e)
{
	if (keycode == 34)
		e->itmax -= 1;
	if (keycode == 31)
		e->itmax += 1;
	return (0);
}

int		pointer_event(int x, int y, t_env *e)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT && e->lock == 0)
	{
		e->mouse_x = (double)x;
		e->mouse_y = (double)y;
		e->mx = ((e->x2 - e->x1) * (double)x) / WIDTH + e->x1;
		e->my = ((e->y2 - e->y1) * (double)y) / HEIGHT + e->y1;
	}
	return (0);
}

int		mouse_event(int button, int x, int y, t_env *e)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / e->zoom) + e->x1;
		y_real = (y / e->zoom) + e->y1;
		if (button == 4)
		{
			e->zoom *= 1.1;
			e->itmax += 1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
		}
		if (button == 5)
		{
			e->zoom /= 1.1;
			e->itmax -= 1;
			e->x1 = x_real - (x / e->zoom);
			e->y1 = y_real - (y / e->zoom);
		}
	}
	return (0);
}
