/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behamon <behamon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:53:04 by behamon           #+#    #+#             */
/*   Updated: 2016/12/23 19:17:10 by behamon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	image_operations(t_env *e)
{
	e->image = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->img_data = mlx_get_data_addr(e->image, &e->bpp, &e->sline, &e->endian);
	if (!ft_strcmp(e->name, "mandelbrot") || !ft_strcmp(e->name, "m"))
		mandelbrot(e);
	else if (!ft_strcmp(e->name, "julia") || !ft_strcmp(e->name, "j"))
		julia(e);
	else if (!ft_strcmp(e->name, "burningship") || !ft_strcmp(e->name, "b"))
		burningship(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	mlx_destroy_image(e->mlx, e->image);
	display_hud(e);
	return (0);
}

int			fractol_init(char *name)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	if (!(e->mlx = mlx_init()))
		return (0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "behamon - fractol");
	e->name = name;
	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "m"))
		mandelbrot_init(e);
	else if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "j"))
		julia_init(e);
	else if (!ft_strcmp(name, "burningship") || !ft_strcmp(name, "b"))
		burningship_init(e);
	mlx_key_hook(e->win, key_hooks, e);
	mlx_hook(e->win, 6, 1L << 6, pointer_event, e);
	mlx_mouse_hook(e->win, mouse_event, e);
	mlx_hook(e->win, 2, 3, mouvement_fractol, e);
	mlx_loop_hook(e->mlx, image_operations, e);
	mlx_loop(e->mlx);
	return (0);
}

int			main(int ac, char **av)
{
	if ((ft_strequ(av[1], "mandelbrot") || ft_strequ(av[1], "m")
				|| ft_strequ(av[1], "julia") || ft_strequ(av[1], "j")
				|| ft_strequ(av[1], "burningship") || ft_strequ(av[1], "b"))
			&& ac == 2)
	{
		if (!fractol_init(av[1]))
		{
			ft_putendl_fd("Error. Please contact an admin", 2);
			return (0);
		}
	}
	else
		ft_putendl("usage: ./fractol [mandelbrot | julia | burningship]");
	return (0);
}
