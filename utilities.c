/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:45:58 by behamon           #+#    #+#             */
/*   Updated: 2016/12/19 17:42:29 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel_to_image(int x, int y, t_env *e, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->sline);
	e->img_data[i] = c;
	e->img_data[++i] = c >> 8;
	e->img_data[++i] = c >> 16;
}

unsigned int	get_color(int a, t_env *e)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (a == e->itmax)
		return (0x0000000);
	r = (a * 5) * e->col.r;
	g = (255 - (a * 10)) * e->col.g;
	b = (255 - (a * 2)) * e->col.b;
	c = (r << 16) + (g << 8) + b;
	return (c);
}

void			display_hud(t_env *e)
{
	char *str0;
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str0 = "Welcome to the world of fractals !";
	str1 = "Use arrows move around";
	str2 = "Press i/o to change fractal iterations";
	str3 = "Press r/g/b to play with colors";
	str4 = "Scroll to zoom to your cursor";
	mlx_string_put(e->mlx, e->win, 10, 10, 0x0FFFFFF, str0);
	mlx_string_put(e->mlx, e->win, 10, 40, 0x0FFFFFF, str1);
	mlx_string_put(e->mlx, e->win, 10, 60, 0x0FFFFFF, str2);
	mlx_string_put(e->mlx, e->win, 10, 80, 0x0FFFFFF, str3);
	mlx_string_put(e->mlx, e->win, 10, 100, 0x0FFFFFF, str4);
}
