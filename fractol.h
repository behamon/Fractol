/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:25:18 by behamon           #+#    #+#             */
/*   Updated: 2016/12/19 17:42:58 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"

# define WIDTH 1350
# define HEIGHT 1200

typedef struct	s_comp
{
	double	re;
	double	im;
}				t_comp;

typedef struct	s_color
{
	char	r;
	char	g;
	char	b;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*img_data;
	char		*name;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	double		mx;
	double		my;
	int			lock;
	int			itmax;
	int			bpp;
	int			sline;
	int			endian;
	t_comp		c;
	t_comp		z;
	t_color		col;
}				t_env;

/*
** Main.c
*/

int				fractol_init(char *name);

/*
** Mandelbrot.c
*/

void			mandelbrot(t_env *e);
void			mandelbrot_init(t_env *e);

/*
** Julia.c
*/

void			julia(t_env *e);
void			julia_init(t_env *e);

/*
** Burningship.c
*/

void			burningship(t_env *e);
void			burningship_init(t_env *e);

/*
** Hooks.c
*/

int				key_hooks(int keycode, t_env *env);
int				mouvement_fractol(int keycode, t_env *e);
int				pointer_event(int x, int y, t_env *e);
int				mouse_event(int button, int x, int y, t_env *e);

/*
** Utilities.c
*/

void			put_pixel_to_image(int x, int y, t_env *env, unsigned int c);
unsigned int	get_color(int a, t_env *e);
void			display_hud(t_env *e);

#endif
